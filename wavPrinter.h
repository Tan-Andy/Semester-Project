#ifndef WAVPRINTER
#define WAVPRINTER
#include "wavManager.h"
#include <iostream>
#include <string>
#include <array>
class WavPrinter{
    void printTitle();
    void printMeta(wav_header waveHeader);
    public:
        WavPrinter()= default;
        void printWavHeader(wav_header waveHeader);
};
#endif