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
    std::cout << "How much delay do you want?" << std::endl;
    std::cin >> temp;
    return temp;
};
float UInterface::gainMenu(){
    float temp;
    std::cout << "How much gain do you want?" << std::endl;
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