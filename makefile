all: Adventure

Adventure: Main.o Setup.o Items.o Door.o Room.o
	g++ Main.o Setup.o Room.o Door.o Items.o -o Adventure

Main.o: Core/Main.cpp Header/Items.h Header/Room.h Header/Setup.h
	g++ -c Core/Main.cpp

Setup.o: Core/Setup.cpp Header/Room.h Header/Items.h
	g++ -c Core/Setup.cpp

Items.o: Core/Items.cpp 
	g++ -c Core/Items.cpp

Door.o: Core/Door.cpp Header/Room.h
	g++ -c Core/Door.cpp

Room.o: Core/Room.cpp Header/Door.h Header/Items.h
	g++ -c Core/Room.cpp

clean:
	rm -rf *.o Adventure
