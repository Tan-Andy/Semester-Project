#include "wavPrinter.h"
#include "wavManager.h"
#include "echo.h"
#include "gain.h"
#include <iostream>
#include <array>
#include "uInterface.h"
#include "normalize.h"

int main(){
    UInterface UI;
    int uChoice =1;
    WavManager wav;
    
    while(uChoice !=0){
        switch(uChoice){
            case 1:
                switch (UI.startMenu()){
                        WavPrinter listy;
                    case 0:
                        uChoice = 0;
                        break;
                    case 1:
                        std::system("clear");
                        if(wav.readFile(UI.fileMenu()) != 0){
                            listy.printWavHeader(wav.getHeader());
                            uChoice = 2;
                        } else {
                            std::cout << "File does not exist or is not a wav file" << std::endl;
                        }
                        break;
                    default:
                        UI.wrongInput();
                        break;
                    }
                break;
            case 2:{
                std::string newFileName = UI.fileNameMenu();
                switch (UI.processorMenu()){
                     case 0: {
                         UI.wrongInput();
                         uChoice = 0;
                         break;
                    }
                    case 1:{
                        //normalization
                        auto normalData = Normalize::process(wav.getData());
                        wav.updateSoundData(normalData);
                        uChoice = 1;
                        break;
                    }
                    case 2:{
                        //echo
                        float gain = UI.gainMenu();
                        int delay = UI.echoMenu();
                        auto echoData = Echo::process(wav.getData(), gain, delay, wav.getNumChannels());
                        wav.updateSoundData(Normalize::process(echoData));
                        uChoice = 1;
                        break;
                    }
                    case 3:{
                        //gain adjustment
                        float gain = UI.gainMenu();
                        auto gainData = Gain::process(wav.getData(), gain);
                        wav.updateSoundData(gainData);
                        
                        uChoice = 1;
                        break;
                    }
                    default:
                        std::system("clear");
                        UI.wrongInput();
                        break;
                }
                //save file
                wav.writeFile(newFileName);
                break;
            }
            default:
                //UI.wrongInput();
                break;
            
        }
    }
    return 1;
}