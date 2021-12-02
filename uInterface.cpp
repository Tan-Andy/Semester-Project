#include "uInterface.h"
#include "wavManager.h"

int UInterface::menu(){
    while(uChoice !=0){
        switch(uChoice){
            case 1:
                switch (menuPrinter()){
                    case 0:
                        uChoice = 0;
                        break;
                    case 1:
                        std::cout << "Type in wav file of your choice (include .wav)" << std::endl;
                        std::cin >> fileName >> std::endl;
                        WavManager wav;
                        if(wav.readFile(fileName) != 0){
                            //print metadata
                            uChoice = 2;
                        } else {
                            std::cout << "File does not exist or is not a wav file" << std::endl;
                        }
                        break;
                }
                break;
            case 2:
                switch (processorMenu()){
                    case 1: 
                        //normalization
                    case 2:
                        //echo
                    case 3:
                        //gain adjustment
                }
                //save file
                uChoice = 1;
                break;
        }
    }
}