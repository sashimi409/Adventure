#include <unordered_map>
#include <string>
#include "Manager.h"
#include "Room.h"


//Default Constructor
//Will eventually be used in the editor half of the program
Manager::Manager()
{
	unordered_map<int, Room*> World;
	Current = nullptr;
}

void Manager::Move(int Dest)
{
	Current = World[Dest];

}

/*
Adds room to World state
Param: pointer to a room object
*/
void Manager::AddRoom(Room* ToAdd)
{
	World.insert({ToAdd->GetID(), ToAdd });

}

/* Gets the ID for a room to move to
 It is based on the index within the current rooms Door Array
*/
int Manager::FindDoor(int Dest)
{
	return Current->Get_door(Dest);
}