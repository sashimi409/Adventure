#include <string>
#include "Room.h"
#include "Door.h"

Door::Door(string name, Room* To):
	Name(name),
	destination(To)
{};

void Door::get_name()
{
	cout << "My name is " << Name << ".\n";
};
