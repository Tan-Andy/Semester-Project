/** @file */
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
    //uChoice = 0 exits the menu while loop
    while(uChoice !=0){
        //case 1: start menu/case 2: processor menu
        switch(uChoice){
            case 1:
                //case 0: exit/case 1: file
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
                std::string newFileName;
                switch (UI.processorMenu()){
                    case 0: {
                         uChoice = 0;
                         break;
                    }
                    case 1:{
                        //normalization
                        auto normalData = Normalize::process(wav.getData());
                        wav.updateSoundData(normalData);
                        newFileName = UI.newfileNameMenu();
                        uChoice = 1;
                        break;
                    }
                    case 2:{
                        //echo
                        float gain = UI.gainMenu();
                        int delay = UI.echoMenu();
                        auto echoData = Echo::process(wav.getData(), gain, delay, wav.getNumChannels());
                        wav.updateSoundData(Normalize::process(echoData));
                        newFileName = UI.newfileNameMenu();
                        uChoice = 1;
                        break;
                    }
                    case 3:{
                        //gain adjustment
                        float gain = UI.gainMenu();
                        auto gainData = Gain::process(wav.getData(), gain);
                        wav.updateSoundData(gainData);
                        newFileName = UI.newfileNameMenu();
                        uChoice = 1;
                        break;
                    }
                    default:
                        std::system("clear");
                        UI.wrongInput();
                        break;
                }
                //save file
                if(uChoice = 1){
                    wav.writeFile(newFileName);
                }
                break;
            }       
        }
    }
    return 1;
}
