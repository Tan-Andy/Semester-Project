//#include "wav.h"
#include "wavPrinter.h"
#include "wavManager.h"
#include "echo.h"
#include <iostream>
#include <array>
int main(){
    WavManager wav;
    wav.readFile ("yes-16-bit-mono.wav");
    WavPrinter listy;
    std::cout << sizeof(wav.getHeader().riff_header) << std::endl;
    listy.printWavHeader(wav.getHeader());
    auto echoData = Echo::process(wav.getData(), 0.1, 10000); //Need to make sure the wav header is updated with the new size of the file
    wav.updateSoundData(echoData);
    wav.updateHeader(10000);
    listy.printWavHeader(wav.getHeader());

    return 1;
}
