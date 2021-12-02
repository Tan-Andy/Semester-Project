#include "wavManager.h"

void WavManager::readFile(const std::string &fileName){
    std::ifstream file(fileName,std::ios::binary | std::ios::in); 
    if(file.is_open()){ 
        file.read((char*)&wavHeader, sizeof(wav_header)); 
        buffer = new short[wavHeader.data_bytes]; 
        //mayber add convert here
        file.read((char*)buffer, wavHeader.data_bytes); 
        file.close(); 
    }else{
         throw std::runtime_error("File " + fileName + " could not be opened");
    }

    if(wavHeader.bit_depth == 16){
        for (int j = 0; j <(wavHeader.data_bytes / wavHeader.sample_alignment); j++){
        soundData.push_back((float)(buffer[j]));  
        }
        //delete buffer; Probably need to delete the buffer
        std::cout<< "This is a 16 bit file" <<std::endl; //Temporary
    }

    else if (wavHeader.bit_depth == 8){
        for (int j = 0; j <(wavHeader.data_bytes / wavHeader.sample_alignment); j++){
        soundData.push_back((float)(buffer[j])); // Should be the formula (((float)(buffer[j]) - 128) / 128)
        }
        std::cout<< "This is a 8 bit file" <<std::endl; //Temporary
    }

    // for(int i =10000; i<30000; i++){
    //    std::cout<<soundData[i]<<std::endl;
    // }
    
}

void WavManager::writeFile(const std::string &newFileName){
    std::ofstream newFile(newFileName, std::ios::out | std::ios::binary);
    newFile.write((char*)&wavHeader, sizeof(wav_header));

    newFile.write((char*) buffer, wavHeader.data_bytes);
    newFile.close();
}
wav_header WavManager::getHeader() const{
    return wavHeader;
}

std::vector<float> WavManager::getData() const{
    return soundData;
}


void WavManager::updateHeader(float delay){
    int additionalData = (delay/static_cast<float>(wavHeader.sample_rate))*wavHeader.byte_rate;
    std::cout<<"Data size to add: "<< additionalData <<std::endl;
    wavHeader.data_bytes += additionalData;
    wavHeader.wav_size += additionalData;
}

void WavManager::updateSoundData(std::vector<float> newData){
    for(int i = 0; i<newData.size(); i++){
        if(i> soundData.size()){
            soundData.push_back(newData[i]);
        }
        else {
            soundData[i] = newData[i];
        }
    }
}
