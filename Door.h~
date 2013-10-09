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

Door::Door(string name, Room* To):
	Name(name),
	destination(To)
{};

void Door::get_name()
{
	cout << "My name is " << Name << ".\n";
}

#endif