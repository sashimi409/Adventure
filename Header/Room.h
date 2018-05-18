#ifndef ROOM_H
#define ROOM_H

#include <string>
#include <vector>
#include <iostream>
#include "Items.h"


using namespace std;


class Room 
{


	//Defining a nested class of door
	struct Door
	{
		string Name;
		int Destination;
	};

	public:
		Room(string);
		bool list_Items();
		bool list_doors();
		void add_Item(Item*);
		void add_Object(Item*);
		void add_door(Door);
		void set_info(string);
		void take_item(int);
		void set_ID(int id) { ID = id; };
		string get_name() { return name;  };
		string get_info() { return info; };
		int Get_door(int);
		int GetID() { return ID; }
		vector<Item*> Items;
		vector<Item*> Objects;
	private:
		string name;
		string info;
		vector<Door> Doors;
		int ID;


};


#endif
