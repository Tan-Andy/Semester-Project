#include "wavPrinter.h"
#include "wavManager.h"
#include "uInterface.h"
#include "normalize.h"
#include "echo.h"
#include "gain.h"
#include <iostream>
/**
 * @brief Main contains logic to display menus and other functions. It controls the UI, processing, and FILE I/O
 * 
 * @return int 
 */
int main(){
    UInterface UI;
    WavManager wav;
    WavPrinter printer;
    int uChoice = 1;
    while(uChoice !=0){
        switch(uChoice){
            case 1:
                switch (UI.startMenu()){
                    
                    case 0:{
                        uChoice = 0;
                        break;
                    }
                    case 1:{
                        std::system("clear");
                        std::string file = UI.fileMenu();
                        if(wav.readFile(file) != 0){
                            printer.printWavHeader(wav.getHeader(), file);
                            uChoice = 2;
                        } else {
                            UI.fileError();
                        }
                        break;
                    }
                    default:
                        UI.wrongInput();
                        break;
                    }
                break;
            case 2:{
                std::string newFileName = UI.newfileNameMenu();
                switch (UI.processorMenu()){
                    case 0: {
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
        }
    }
    return 1;
}
