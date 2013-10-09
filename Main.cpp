#include <iostream>
#include <vector>
#include <string>
#include "Items.h"
#include "Room.h"
#include "Setup.h"



int get_input();
void help();
string info(Room Place);
int choice;
void Set_current(vector<Room>&, int, Room*&);
bool list_inventory(vector<Item*>&);
using namespace std;



int main()
{
	vector<Room> Rooms;
	vector<Item> Items;
	Items.reserve(10);
	vector<Item*> Inventory;
	Inventory.reserve(5);
	setup(Rooms, Items);
	Room* current = &Rooms[1];
	cout << info(*current) << endl;
	help();
	do
	{
		choice = get_input();
		cout << endl;
		switch(choice)
		{
		case 0:
			help();
			break;
		case 1: cout << "Where would you like to move?" << endl;
			bool Dr;
			Dr = current -> list_doors();
			if(Dr)
			{
				int choiceWhere;
				cout << ">";
				cin >> choiceWhere;
				Set_current(Rooms,choiceWhere, current);
				cout <<info(*current) << endl;
			}
			break;
		case 2: cout << "What would you like to take?" << endl;
			bool itm;
			itm = current -> list_Items();
			if(itm)
			{
				short choiceWhat;
				cout << ">";
				cin >> choiceWhat;
				Inventory.push_back(current -> Items[choiceWhat]);
				current -> take_item(choiceWhat);
			}
			break;
		case 3:cout << info(*current) << endl;
			break;
		case 4:
			cout << "You currently have the following:" <<endl;
			list_inventory(Inventory);
			break;
		case 5:
			bool interact;
			cout << "What would you like to use?" <<endl;
			interact = list_inventory(Inventory);
			if(interact)
			{
				short choiceWhat;
				bool Made;
				cout << ">";
				cin >> choiceWhat;
				Made = Inventory[choiceWhat] -> interact(current -> Objects, Items);
				if(Made)
				{
					Item* Thing;
					short Indices;
					Indices = Items.size() - 1;
					Thing = &Items[Indices];
					current -> add_Item(Thing);
				}
				Inventory.erase(Inventory.begin() + choiceWhat);
			}
			break;
		case 9: cout << "Goodbye" << endl;
			break;
		default: cout << "That is not a valid input" << endl;
			break;
		}
		cout << endl;
	}
	while(choice != 9);


	return 0;
}

void Set_current(vector<Room>& Rooms, int Choice, Room*& current)
{
	current = current -> Get_door(Choice);
}

bool list_inventory(vector<Item*>& Inventory)
{
	int index = 0;
	if(Inventory.size() > 0)
	{
		vector<Item*>::iterator Thing;
		for(Thing = Inventory.begin(); Thing != Inventory.end();++Thing)
		{
			Item* To;
			To = *Thing;
		
			
			cout << index << " - " << To -> get_name() << endl;
			++index;
		}
		return true;
	}
	else{ cout << "Nothing" << endl; return false;};
}

void help()
{
	cout << "Commands:" <<endl;
	cout << "0 - Help." <<endl;
	cout << "1 - Move."<<endl;
	cout << "2 - Pick up something" <<endl;
	cout << "3 - Where am I?" << endl;
	cout << "4 - What is in my inventory?" << endl;
	cout << "5 - Interact" << endl;
	cout << "9 - Quit" << endl;
}

int get_input()
{
	cout << ">";
	cin >> choice;

	return choice;
}

string info(Room Place)
{
	return Place.get_info();
}

