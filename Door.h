#ifndef DOOR_H
#define DOOR_H
#include "Room.h"

using namespace std;


class Door
{
	public:
		Item(string, Room*);
		void get_name();
	private:
		Room* destinaiton;
		string Name;

};


#endif
