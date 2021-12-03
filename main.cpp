#include "wavPrinter.h"
#include "wavManager.h"
#include "echo.h"
#include <iostream>
#include <array>
#include "uInterface.h"

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
                        
                        if(wav.readFile(UI.fileMenu()) != 0){
                            listy.printWavHeader(wav.getHeader());
                            uChoice = 2;
                        } else {
                            std::cout << "File does not exist or is not a wav file" << std::endl;
                        }
                        break;
                }
                break;
            case 2:
                switch (UI.processorMenu()){
                    case 1: 
                        //normalization
                    case 2:
                        UI.echoMenu();
                    case 3:
                        //gain adjustment
                        UI.gainMenu();
                }
                //save file
                wav.writeFile("");
                uChoice = 1;
                break;
        }
    }
    std::system("clear");
    return 1;
}