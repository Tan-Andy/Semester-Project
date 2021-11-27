#include "wavPrinter.h"

std::ostream &operator<<(std::ostream &os, const wav_header &waveHeader){
        os << "Riff: " << std::string(waveHeader.riff_header) << std::endl;
        os << "Wav Size: " <<waveHeader.wav_size << std::endl;
        os << "Wave Header: " <<waveHeader.wave_header << std::endl;
        os << "fmt header: " <<waveHeader.fmt_header << std::endl;
        os << "fmt chunk: " <<waveHeader.fmt_chunk_size << std::endl;
        os << "Audio Format: " <<waveHeader.audio_format << std::endl;
        os << "Channels: " <<waveHeader.num_channels << std::endl;
        os << "Sample Rate: " <<waveHeader.sample_rate << std::endl;
        os << "Byte Rate: " <<waveHeader.byte_rate << std::endl;
        os << "Sample Alignment: " <<waveHeader.sample_alignment << std::endl;
        os << "Bit Depth: " <<waveHeader.bit_depth << std::endl;
        os << "Data Header: " <<waveHeader.data_header << std::endl;
        os << "Data Bytes: " <<waveHeader.data_bytes << std::endl;
        return os;
};
void WavPrinter::printTitle(){
    std::cout<< "------Metadata------" << std::endl;
};
void WavPrinter::printMeta(wav_header waveHeader){
    std:: cout<< waveHeader;
};

void WavPrinter::printWavHeader(wav_header waveHeader){
    printTitle();
    printMeta(waveHeader);
};

std::string WavPrinter::nullRemover(char array[]){
    std::string holder;
    for (int i = 0; i <sizeof(array); i++){
        if(array[i]!= NULL){
            array[i] = ' ';
        }
    }
    return std::string(array);
};