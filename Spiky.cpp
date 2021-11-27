//#include "wav.h"
#include "wavPrinter.h"
#include "wavManager.h"
#include <iostream>
#include <array>
int main(){
    WavManager wav;
    wav.readFile ("yes-16-bit-mono.wav");
    WavPrinter listy;
    std::cout << sizeof(wav.getHeader().riff_header) << std::endl;
    listy.printWavHeader(wav.getHeader());
    wav.writeFile("yes-8.wav");
    return 1;
}