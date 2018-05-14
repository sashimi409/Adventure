#ifndef MANAGER_H
#define MANAGER_H



#include <string>
#include <unordered_map>
#include "Room.h"

using namespace std;

/*
This will be the largest class.
Will handle my world State
*/
class Manager 
{
public:

	//Called to change Current location
	void Move(int);
	Manager();
	void AddRoom(Room*);

private:

	//Main container that holds all data
	unordered_map<int, Room*> World;
	//Refers to where the player's character is located
	Room* Current;
	
	

};


#endif 