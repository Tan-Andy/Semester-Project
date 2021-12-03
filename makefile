all: spiky

spiky: main.cpp uInterface.o wavManager.o wavPrinter.o echo.o
	g++ -std=c++11 -o spiky main.cpp uInterface.o wavManager.o wavPrinter.o echo.o
uInterface: uInterface.h uInterface.cpp
	g++ -std=c++11 -c uInterface.cpp
wavManager: wavManager.h wavManager.cpp
	g++ -std=c++11 -c wavManager.cpp
wavPrinter: wavPrinter.h wavPrinter.cpp
	g++ -std=c++11 -c wavPrinter.cpp
echo: echo.h echo.cpp
	g++ -std=c++11 -c echo.cpp
clean:
	rm *.o spiky