#ifndef WAVPRINTER
#define WAVPRINTER
#include "wavManager.h"
#include <iostream>
/**
 * @brief WavPrinter is a class that holds functions to print the metadata of a wav file
 * 
 */
class WavPrinter{
    /**
     * @brief prints the cool title for the metadata
     * 
     */
    void printTitle();
    /**
     * @brief Prints the filename and metadata.
     * 
     * @param waveHeader :wave header we are trying to print.
     * @param fileName :filename of the given wav file.
     */
    void printMeta(wav_header waveHeader, std::string fileName);
    public:
        WavPrinter()= default;
        /**
         * @brief Called to print important parts of the wav header (metadata) and title.
         * 
         * @param waveHeader :wave header we are trying to print.
         * @param fileName :filename of the given wav file.
         */
        void printWavHeader(wav_header waveHeader, std::string fileName);
};
#endif