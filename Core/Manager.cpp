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

/*
Changes the currently active room
Param: Room ID to change to
*/
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
 Param: Index of the door vector contained within the current room
 Output: Room ID number to switch to
*/
int Manager::FindDoor(int Dest)
{
	return Current->Get_door(Dest);
}