#ifndef U_INTERFACE
#define U_INTERFACE
#include <iostream>
#include <array>
#include "wavManager.h"


class UInterface{
    public:
        UInterface() = default;
        int startMenu();
        int processorMenu();
        int echoMenu();
        float gainMenu();
        std::string fileMenu();
        void wrongInput();
        std::string fileNameMenu();
};

#endif