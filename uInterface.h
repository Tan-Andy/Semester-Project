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
         * @brief startMenu prints out the starting menu
         * 
         * @return int :user's choice
         */
        int startMenu();
        /**
         * @brief processorMenu prints out a menu of the processors
         * 
         * @return int :user's choice
         */
        int processorMenu();
        /**
         * @brief echoMenu prints out the small echo menu.
         * 
         * @return int :the user's choice of delay
         */
        int echoMenu();
        /**
         * @brief gainMenu prints out the small gain menu.
         * 
         * @return float :the user's choice of gain
         */
        float gainMenu();
        /**
         * @brief fileMenu prints out the small file menu.
         * 
         * @return std::string :User's file name
         */
        std::string fileMenu();
        /**
         * @brief wrongInput prints out a wrongInput message.
         * 
         */
        void wrongInput();
        /**
         * @brief newfileNameMenu prints out the new file menu.
         * 
         * @return std::string the user's file name for the wav file.
         */
        std::string newfileNameMenu();
        /**
         * @brief fileError prints out an error message due to invalid file type or file could not be found.
         * 
         */
        void fileError();
};

#endif