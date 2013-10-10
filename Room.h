#ifndef ROOM_H
#define ROOM_H

#include <string>
#include <vector>
#include <iostream>
#include "Items.h"


using namespace std;


class Room 
{

	public:
		Room(string);
		bool list_Items();
		bool list_doors();
		void add_Item(Item*);
		void add_Object(Item*);
		void add_door(Room*);
		void set_info(string);
		void take_item(int);
		string get_name();
		string get_info();
		string Enterance();
		Room* Get_door(int);
		vector<Item*> Items;
		vector<Item*> Objects;
	private:
		string name;
		string Enter;
		string info;
		vector<Room*> Doors;


};


#endif
