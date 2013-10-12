#ifndef DOOR_H
#define DOOR_H
#include <string>
#include "Room.h"


using namespace std;


class Door
{
	public:
		Door(string, Room*);
		void get_name();
	private:
		Room* destination;
		string Name;

};


#endif
