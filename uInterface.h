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
        int startMenu();
        int processorMenu();
        int echoMenu();
        float gainMenu();
        std::string fileMenu();
        void wrongInput();
        std::string newfileNameMenu();
        void fileError();
};

#endif