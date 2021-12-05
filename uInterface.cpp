#include "uInterface.h"
/**
 * @brief startMenu prints out the starting menu and returns the user's choice
 * 
 * @return int
 */
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
/**
 * @brief processorMenu prints out a menu of the processors and returns the user's choice
 * 
 * @return int 
 */
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
/**
 * @brief echoMenu prints out the small echo menu and returns the user's choice of delay
 * 
 * @return int 
 */
int UInterface::echoMenu(){
    int temp;
    std::cout << "How much delay do you want (type a # from 0-300k)? (Units are in samples)" << std::endl;
    std::cin >> temp;
    return temp;
};
/**
 * @brief gainMenu prints out the small gain menu and returns the user's choice of gain
 * 
 * @return float 
 */
float UInterface::gainMenu(){
    float temp;
    std::cout << "How much gain do you want? (Gain works between 0 & 1 (ex: 0.5)" << std::endl;
    std::cin >> temp;
    return temp;
};
/**
 * @brief fileMenu prints out the small file menu and returns the user's file name
 * 
 * @return std::string 
 */
std::string UInterface::fileMenu(){
    std::string fileName;
    std::cout << "Type in wav file of your choice (include .wav)" << std::endl;
    std::cin >> fileName;
    return fileName;
};
/**
 * @brief wrongInput prints out a small message that the user chose a wrong input
 * 
 */
void UInterface::wrongInput(){
    std::cout << "Invalid input" <<std::endl;
}
/**
 * @brief startMenu prints out the starting menu and returns the user's choice
 * 
 * @return std::string 
 */
std::string UInterface::newfileNameMenu(){
        std::string fileName;
        std::cout<< "type in the file name for your new WAV (include.wav)" <<std::endl;
        std::cin >> fileName;
        return fileName;
}

void UInterface::fileError(){
    std::cout << "File does not exist or is not a wav file" << std::endl;
}