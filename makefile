all: spiky
spiky: Spiky.cpp wavManager.o wavPrinter.o
	g++ -o spiky Spiky.cpp wavManager.o wavPrinter.o
wavManager: wavManager.h wavManager.cpp
	g++ -c wavManager.cpp
wavPrinter: wavPrinter.h wavPrinter.cpp
	g++ -c wavPrinter.cpp
clean:
	rm *.o spiky