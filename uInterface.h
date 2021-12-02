#ifndef U_INTERFACE
#define U_INTERFACE
#include <iostream>
#include <array>
class UInterface{
    private:
        int uChoice = 1;
        std::array<char,20> fileName;
    public:
        int menu();
        int menuPrinter();
        int processorMenu();
};

#endif