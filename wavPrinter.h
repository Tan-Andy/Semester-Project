#ifndef WAVPRINTER
#define WAVPRINTER
#include "wavManager.h"
#include <iostream>
/**
 * @brief WavPrinter is a class that holds functions to print the metadata of a wav file
 * 
 */
class WavPrinter{
    void printTitle();
    void printMeta(wav_header waveHeader, std::string fileName);
    public:
        WavPrinter()= default;
        void printWavHeader(wav_header waveHeader, std::string fileName);
};
#endif