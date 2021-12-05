#ifndef U_INTERFACE
#define U_INTERFACE
#include <iostream>
#include "wavManager.h"
/**
 * @brief UInterface is a class that is solely made of functions that print menus and return user input
 * 
 */
class UInterface{
    public:
        UInterface() = default;
        /**
         * @brief startMenu prints out the starting menu and returns the user's choice
         * 
         * @return int 
         */
        int startMenu();
        /**
         * @brief processorMenu prints out a menu of the processors and returns the user's choice.
         * 
         * @return int 
         */
        int processorMenu();
        /**
         * @brief echoMenu prints out the small echo menu and returns the user's choice of delay.
         * 
         * @return int 
         */
        int echoMenu();
        /**
         * @brief gainMenu prints out the small gain menu and returns the user's choice of gain
         * 
         * @return float 
         */
        float gainMenu();
        /**
         * @brief fileMenu prints out the small file menu and returns the user's file name.
         * 
         * @return std::string 
         */
        std::string fileMenu();
        /**
         * @brief wrongInput prints out a small message that the user chose a wrong input.
         * 
         */
        void wrongInput();
        /**
         * @brief newfileNameMenu prints out the new file menu and returns the user's file name for the wav file.
         * 
         * @return std::string 
         */
        std::string newfileNameMenu();
        /**
         * @brief fileError prints out an error message due to invalid file type or file could not be found.
         * 
         */
        void fileError();
};

#endif