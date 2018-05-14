#include <unordered_map>
#include <string>
#include "Manager.h"
#include "Room.h"


//Default Constructor
Manager::Manager()
{
	unordered_map<int, Room*> World;
	Current = nullptr;
}

void Manager::Move(int)
{


}

/*
Adds room to World state
Param: pointer to a room object
*/
void Manager::AddRoom(Room* ToAdd)
{
	World.insert({ToAdd->GetID(), ToAdd });

}