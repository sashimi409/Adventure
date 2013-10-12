#include <vector>
#include <string>
#include <iostream>
#include "Items.h"

Item::Item(string name,string String = "",string desc = "", string make = "", string make_interact =  "",string make_description = "", bool needs = false, string needs_what = ""):
	Name(name),
	Interact(String),
	Description(desc),
	Make(make),
	Make_interact(make_interact),
	Make_description(make_description),
	Interact_need(needs),
	Interact_item(needs_what)
{
};

string Item::get_name()
{
	return Name;
};

void Item::get_description()
{
	cout << Description << endl;
}

bool Item::interact(vector<Item*>& Objects, vector<Item>& Items)
{
	bool Made = false;
	if(Interact_need)
	{
		Item* Item1;
		bool found = false;

		vector<Item*>::iterator Find;
		if( Objects.size() >0)
		{
			for(Find = Objects.begin(); Find != Objects.end(); ++Find)
			{
				string name;
				Item* Thing;
				Thing = *Find;
				name = Thing -> get_name();
				if(name == Interact_item)
				{
					Item1 = *Find;
					found = true;
					break;
				}
			}
		}
		if(found)
		{
			Made = Item1 -> interact(Objects,Items);
		}
		else
		{
			cout << "Nothing special happens. Perhaps try another room.";
		}
	}
	else
	{
		if(Make != "")
		{
			cout << Interact << endl;
			Item New(Make,Make_interact,Make_description);
			Items.push_back(New);
			Made = true;
			return Made;
		}
		else
		{
			cout << Interact << endl;
		}
	}
	return Made;
};

