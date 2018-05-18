#include <vector>
#include "../Header/Room.h"
#include "../Header/Items.h"


Room :: Room(string name):
	name(name)
{
	vector<Item*> Objects;

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
		vector<Door>::iterator Passage;
		for(Passage = Doors.begin(); Passage != Doors.end();++Passage)
		{
						
			cout << index << " - " << Passage->Name << endl;
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

void Room :: add_door(Door room)
{
	Doors.push_back(room);
};


void Room::set_info(string Info)
{
	info = Info;
}


int Room::Get_door(int Choice)
{
	return Doors[Choice].Destination;
}

void Room::take_item(int Choice)
{
	cout << "You took a(n) " << Items[Choice] -> get_name()<< endl;
	Items[Choice] -> get_description();
	Items.erase(Items.begin() + Choice);
}
