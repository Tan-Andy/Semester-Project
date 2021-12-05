#include "wavPrinter.h"
/**
 * @brief Insertion operator overloader, so '<<' leads to printing the metadata of the file
 * 
 * @param os :the output stream
 * @param waveHeader :the wav_header object
 * @return std::ostream& 
 */
std::ostream &operator<<(std::ostream &os, const wav_header &waveHeader){
    os << "Sample Rate: " <<waveHeader.sample_rate << std::endl;
    os << "Bit Rate: " <<waveHeader.bit_depth << std::endl;
    os << "Channels (1 for mono/2 for stereo): " <<waveHeader.num_channels << std::endl;
    return os;
};

void WavPrinter::printTitle(){
    std::cout<< "------Metadata------" << std::endl;
};

void WavPrinter::printMeta(wav_header waveHeader, std::string fileName){
    std::cout << "File Name: " << fileName <<std::endl;
    std::cout << waveHeader;
};

void WavPrinter::printWavHeader(wav_header waveHeader, std::string fileName){
    printTitle();
    printMeta(waveHeader, fileName);
};
