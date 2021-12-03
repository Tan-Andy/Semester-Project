#ifndef U_INTERFACE
#define U_INTERFACE
#include <iostream>
#include <array>
class UInterface{
    public:
        int startMenu();
        int processorMenu();
        int echoMenu();
        int gainMenu();
        std::string fileMenu();
};

#endif