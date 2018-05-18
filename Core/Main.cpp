#include <iostream>
#include <vector>
#include <string>
#include "../Header/Items.h"
#include "../Header/Room.h"
#include "../Header/Manager.h"



int get_input();
void help();
int choice;
bool list_inventory(vector<Item*>&);
using namespace std;



int main()
{
	//Instantiate The manager class
	Manager WorldState;

	//Create a test room
	Room Menu("Menu");
	Menu.set_info("This is a test object");
	Menu.set_ID(3);

	//Initial set up of the Manager object
	WorldState.AddRoom(&Menu);
	WorldState.Move(3);
	Room* current = WorldState.get_current();


	//Game Loop
	cout << current->get_info() << endl;
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
				int Dest = WorldState.FindDoor(choiceWhere);
				WorldState.Move(Dest);
				cout << current ->get_info() << endl;
			}
			break;
		case 2:cout << current->get_info() << endl;
			break;
		case 9: cout << "Goodbye" << endl;
			break;
		default: cout << "That is not a valid input" << endl;
			break;
		}
		cout << endl;
		Room* current = WorldState.get_current();
	}
	while(choice != 9);


	return 0;
}

/*Function to list items on the characters person
Currently not available to be used
*/
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

/*
Displays the commands to interact with the world state
*/
void help()
{
	cout << "Commands:" <<endl;
	cout << "0 - Help." <<endl;
	cout << "1 - Move."<<endl;
	cout << "2 - Where am I?" << endl;
	cout << "9 - Quit" << endl;
}

/* Gathers input from the player based on the commands found in the help section
*/
int get_input()
{
	cout << ">";
	cin >> choice;

	return choice;
}

