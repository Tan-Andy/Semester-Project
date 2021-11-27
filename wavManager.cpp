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
}

void WavManager::writeFile(const std::string &newFileName){
    std::ofstream newFile(newFileName, std::ios::out | std::ios::binary);
    newFile.write((char*)&wavHeader, sizeof(wav_header));
    newFile.write((char*) buffer, wavHeader.data_bytes);
    newFile.close();
}
wav_header WavManager::getHeader(){
    return wavHeader;
}
