#include "wavManager.h"

int WavManager::readFile(const std::string &fileName){
    std::ifstream file(fileName,std::ios::binary | std::ios::in); 
    if(file.is_open()){ 
        file.read((char*)&wavHeader, sizeof(wav_header)); 
        //remove endline char and avoid a seg fault
        std::string str_riff =std::string(std::begin(wavHeader.riff_header), std::end(wavHeader.riff_header));
        std::string str_wave =std::string(std::begin(wavHeader.wave_header), std::end(wavHeader.wave_header));
        if("RIFF" == str_riff && "WAVE" == str_wave){
            if(wavHeader.bit_depth == 16){

                short* buffer = new short[wavHeader.data_bytes]; 
                file.read((char*)buffer, wavHeader.data_bytes);

                for (int j = 0; j <(wavHeader.data_bytes / wavHeader.sample_alignment * wavHeader.num_channels); j++){
                soundData.push_back((float)(buffer[j]) / 32768);  
                }
                delete[] buffer;
            }

            else if (wavHeader.bit_depth == 8){
                unsigned char* buffer = new unsigned char[wavHeader.data_bytes];
                file.read((char*)buffer, wavHeader.data_bytes);

                for (int j = 0; j <(wavHeader.data_bytes / wavHeader.sample_alignment * wavHeader.num_channels); j++){
                soundData.push_back((float)(buffer[j]-128) / 128); 
                }
            
                delete[] buffer;
            }
        }
    }
    else{
         return 0;
    }

    file.close();
    return 1;   
}

void WavManager::writeFile(const std::string &newFileName){
    std::ofstream newFile(newFileName, std::ios::out | std::ios::binary);
    newFile.write((char*)&wavHeader, sizeof(wav_header));


    if(wavHeader.bit_depth == 16){
            short* buffer = new short[soundData.size()];

            for(int i = 0; i < soundData.size(); i++){
                buffer[i] = soundData[i] * 32768;
            }

            newFile.write((char*) buffer, wavHeader.data_bytes);
            delete[] buffer;
    }

    else { 
            unsigned char* buffer = new unsigned char[soundData.size()];

            for(int i = 0; i<soundData.size(); i++){
                buffer[i] = ((soundData[i] * 128) + 128);
            }

            newFile.write((char*) buffer, wavHeader.data_bytes);
            delete[] buffer;
    }
    //Clearing the soundData vector to allow the program to process more than 1 file per execution.
    soundData.clear(); 

    //Closing the file stream
    newFile.close();
}

wav_header WavManager::getHeader() const{
    return wavHeader;
}

std::vector<float> WavManager::getData() const{
    return soundData;
}

int WavManager::getNumChannels() const{
    return wavHeader.num_channels;
}

void WavManager::updateSoundData(std::vector<float> newData){
    
    //updating the header

    wavHeader.data_bytes = wavHeader.sample_alignment * newData.size() / wavHeader.num_channels;
    wavHeader.wav_size = wavHeader.data_bytes + 36;

    //updating the actual soundData vector

    for(int i = 0; i<newData.size(); i++){
        if(i> soundData.size()){
            soundData.push_back(newData[i]);
        }
        else {
            soundData[i] = newData[i];
        }
    }
}
