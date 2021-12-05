all: wav

wav: main.cpp uInterface.o wavManager.o wavPrinter.o echo.o gain.o normalize.o
	g++ -std=c++11 -o wav main.cpp uInterface.o wavManager.o wavPrinter.o echo.o gain.o normalize.o
uInterface: uInterface.h uInterface.cpp
	g++ -std=c++11 -c uInterface.cpp
wavManager: wavManager.h wavManager.cpp
	g++ -std=c++11 -c wavManager.cpp
wavPrinter: wavPrinter.h wavPrinter.cpp
	g++ -std=c++11 -c wavPrinter.cpp
echo: echo.h echo.cpp
	g++ -std=c++11 -c echo.cpp
gain: gain.h gain.cpp
	g++-std=c++11 -c gain.cpp
normalize: normalize.h normalize.cpp
	g++-std=c++11 -c gain.cpp
clean:
	rm *.o wav