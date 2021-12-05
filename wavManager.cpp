#include "wavManager.h"
/**
 * @brief readFile creates an input stream to store the header, and if the file is a wav file, it will 
 * store the sound data and convert the data to be between -1 & 1.
 * 
 * @param fileName 
 * @return int :returns 1 or 0 to signify if the file is a wav.
 */
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
/**
 * @brief writeFile creates an output stream to write the header and data into a wav file.
 * It detects the bit depth and stores the data into the buffer for writing.
 * 
 * @param newFileName 
 */
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
    soundData.clear(); //empties the contents of the vector allowing for repeated use of the program
    newFile.close();
}
/**
 * @brief getHeader is a getter to return the entire wavHeader struct.
 * 
 * @return wav_header :returns the entire wav header struct
 */
wav_header WavManager::getHeader() const{
    return wavHeader;
}
/**
 * @brief WavManager is a getter to return the soundData vector.
 * 
 * @return std::vector<float> :returns vector that holds the sound data of the wav file
 */
std::vector<float> WavManager::getData() const{
    return soundData;
}
/**
 * @brief getNumChannels is a getter to return the number of channels.
 * 
 * @return int :Number of channels
 */
int WavManager::getNumChannels() const{
    return wavHeader.num_channels;
}
/**
 * @brief updateSoundData updates the data bytes and wav size in the header when echo is used. 
 * The function also expands the vector soundData if echo adds more samples.
 * 
 * @param newData :New data that needs to be copied to SoundData
 */
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
