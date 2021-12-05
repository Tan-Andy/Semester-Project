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
/**
 * @brief prints the cool title for the metadata
 * 
 */
void WavPrinter::printTitle(){
    std::cout<< "------Metadata------" << std::endl;
};
/**
 * @brief Prints the filename and metadata.
 * 
 * @param waveHeader :wave header we are trying to print.
 * @param fileName :filename of the given wav file.
 */
void WavPrinter::printMeta(wav_header waveHeader, std::string fileName){
    std::cout << "File Name: " << fileName <<std::endl;
    std::cout << waveHeader;
};
/**
 * @brief Called to print important parts of the wav header (metadata) and title.
 * 
 * @param waveHeader :wave header we are trying to print.
 * @param fileName :filename of the given wav file.
 */
void WavPrinter::printWavHeader(wav_header waveHeader, std::string fileName){
    printTitle();
    printMeta(waveHeader, fileName);
};
