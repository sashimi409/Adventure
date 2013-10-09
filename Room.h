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
		const string name;
		string Enter;
		string info;
		vector<Room*> Doors;


};

Room :: Room(string name):
	name(name)
{
	vector<Item*> Objects;
	vector<Room*> Doors;

};

bool Room :: list_Items()
{
	int index = 0;
	if(Items.size() > 0)
	{
		vector<Item*>::iterator thing;
		for(thing = Items.begin(); thing != Items.end(); ++thing)
		{
			Item* itm;
			itm = *thing;
			cout << index << " - " << itm-> get_name() << endl;
			++index;
		}
		return true;
	}
	else{ cout << "There are no items here" << endl; return false;};
};

bool Room :: list_doors()
{
	int index = 0;
	if(Doors.size() > 0)
	{
		vector<Room*>::iterator Door;
		for(Door = Doors.begin(); Door != Doors.end();++Door)
		{
			Room* To;
			To = *Door;
		
			
			cout << index << " - " << To -> get_name() << endl;
			++index;
		}
		return true;
	}
	else{ cout << "There are no exits here" << endl; return false;};
};

void Room :: add_Object(Item* thing)
{
	Objects.push_back(thing);
};

void Room :: add_Item(Item* thing)
{
	Items.push_back(thing);
};

void Room :: add_door(Room* room)
{
	Doors.push_back(room);
};

string Room::get_name()
{
	return name;
};

string Room::get_info()
{
	return info;
};

void Room::set_info(string Info)
{
	info = Info;
}

string Room::Enterance()
{
	return Enter;
}

Room* Room::Get_door(int Choice)
{
	return Doors[Choice];
}

void Room::take_item(int Choice)
{
	cout << "You took a(n) " << Items[Choice] -> get_name()<< endl;
	Items[Choice] -> get_description();
	Items.erase(Items.begin() + Choice);
}



#endif
