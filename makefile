all: Adventure

Adventure: Main.o Setup.o Items.o Door.o Room.o
	g++ Main.o Setup.o -o Adventure

Main.o: Main.cpp Items.h Room.h Setup.h
	g++ -c Main.cpp

Setup.o: Setup.cpp Room.h Items.h
	g++ -c Setup.cpp

Items.o: Items.cpp 
	g++ -c Items.cpp

Door.o: Door.cpp Room.h
	g++ -c Door.cpp

Room.o: Room.cpp Door.h Items.h
	g++ -c Room.cpp

clean:
	rm -rf *o Adventure
