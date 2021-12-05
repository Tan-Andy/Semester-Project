#include "uInterface.h"

int UInterface::startMenu(){
    int temp;
    std::cout << "Welcome to Wav your problems away" << std::endl;
    std::cout << "---Start Menu---" << std::endl;
    std::cout << "Enter:" << std::endl;
    std::cout << "0. Exit" << std::endl;
    std::cout << "1. Start File Process" << std::endl;
    std::cin >> temp;
    return temp;
};

int UInterface::processorMenu(){
    int temp;
    std::cout << "---Select Processor---" << std::endl;
    std::cout << "0. Exit" << std::endl;
    std::cout << "1. Normalization" << std::endl;
    std::cout << "2. Echo" << std::endl;
    std::cout << "3. Gain Adjustment" << std::endl;
    std::cin >> temp;
    return temp;
};

int UInterface::echoMenu(){
    int temp;
    std::cout << "How much delay do you want (type a # from 0-300k)? (Units are in samples)" << std::endl;
    std::cin >> temp;
    return temp;
};

float UInterface::gainMenu(){
    float temp;
    std::cout << "How much gain do you want? (Gain works between 0 & 1 (ex: 0.5)" << std::endl;
    std::cin >> temp;
    return temp;
};

std::string UInterface::fileMenu(){
    std::string fileName;
    std::cout << "Type in wav file of your choice (include .wav)" << std::endl;
    std::cin >> fileName;
    return fileName;
};

void UInterface::wrongInput(){
    std::cout << "Invalid input" <<std::endl;
}

std::string UInterface::newfileNameMenu(){
        std::string fileName;
        std::cout<< "type in the file name for your new WAV (include.wav)" <<std::endl;
        std::cin >> fileName;
        return fileName;
}

void UInterface::fileError(){
    std::cout << "File does not exist or is not a wav file" << std::endl;
}