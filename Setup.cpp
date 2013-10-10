#include <vector>
#include <string>
#include "Room.h"
#include "Items.h"

void Make_doors(vector<Room>& Rooms, string rm1, string rm2)
{
	Room* room1;
	Room* room2;
	vector<Room>::iterator Find;
	for(Find = Rooms.begin(); Find != Rooms.end(); ++Find)
	{
		string name;
		name = Find -> get_name();
		if(name == rm1)
		{
			room1 = &*Find;
			break;
		}

	}

	for(Find = Rooms.begin(); Find != Rooms.end(); ++Find)
	{
		string name;
		name = Find -> get_name();
		if(name == rm2)
		{
			room2 = &*Find;
			break;
		}

	}

	room1 -> add_door(room2);
	room2 -> add_door(room1);
}
void Make_Items(vector<Item>& Items,vector<Room>& Rooms, string rm, string itm)
{
	Room* room1;
	Item* item1;

	vector<Room>::iterator Find;
	for(Find = Rooms.begin(); Find != Rooms.end(); ++Find)
	{
		string name;
		name = Find -> get_name();
		if(name == rm)
		{
			room1 = &*Find;
			break;
		}

	}

	vector<Item>::iterator Find2;
	for(Find2 = Items.begin(); Find2 != Items.end(); ++Find2)
	{
		string name;
		name = Find2 -> get_name();
		if(name == itm)
		{
			item1 = &*Find2;
			break;
		}

	}

	room1 -> add_Item(item1);
}
void Make_Objects(vector<Item>& Items,vector<Room>& Rooms, string rm, string itm)
{
	Room* room1;
	Item* item1;

	vector<Room>::iterator Find;
	for(Find = Rooms.begin(); Find != Rooms.end(); ++Find)
	{
		string name;
		name = Find -> get_name();
		if(name == rm)
		{
			room1 = &*Find;
			break;
		}

	}
	vector<Item>::iterator Find2;
	for(Find2 = Items.begin(); Find2 != Items.end(); ++Find2)
	{
		string name;
		name = Find2 -> get_name();
		if(name == itm)
		{
			item1 = &*Find2;
			break;
		}

	}

	room1 -> add_Object(item1);
}
void intro()
{
	cout << "Welcome to this short adventure." <<endl;
	cout << "Sadly this program is very particular, so please use the given commands." <<endl;
	cout << "If you forget them, use 0 for the help menu."<<endl;
	cout << "There is something in here that was left for you." <<endl;
	cout << "Your goal is to find it." << endl;
	cout << "You will have to navigate and interact with your enviorment" << endl;
	cout << "I wish you the best of luck." << endl;
	cout << "-Salim" << endl;
	cout << "---------------------------------------------------" << endl;
}
void setup(vector<Room>& Rooms,vector<Item>& Items)
{
	string Emily;
	Emily = "You figured it out!";
	Room Kitchen("Kitchen");
	Room Dining("Dining Room");
	Kitchen.set_info("You are in a room with granite countertops and cabinets along the walls. In places there are appliances; a fridge, stove, and oven. Obviously it is a kitchen.There are many cooking implements and a key on the counter. There is a doorway, through which you can see what looks like the corner of a table");
	Dining.set_info("You are in a dining room. It is not very large but the table in the middle grabs you eye. One reason for this is it is a deep black and looks like  polished ebony. There are some papers scattered across it. In the middle though there is a chest. it appears to be very old. There is a doorway that leads off into a kitchen");
	Item Key("Key","","The Key appears to be very old. It looks like it might go to an old chest.","","","",true, "Chest");
	Item Chest("Chest","The Chest Opens and a note falls out","", "Note", Emily,"A note with a hand written message scrawled on it",false,"");
	Items.push_back(Key);
	Items.push_back(Chest);
	Rooms.push_back(Kitchen);
	Rooms.push_back(Dining);
	Make_Items(Items, Rooms, "Kitchen","Key");
	Make_Objects(Items, Rooms, "Dining Room","Chest");
	Make_doors(Rooms, "Kitchen", "Dining Room");
	intro();
}
