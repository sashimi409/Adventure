#ifndef ITEMS_H
#define ITEMS_H
#include <vector>

using namespace std;



class Item
{
	public:
		Item(string,string, string,string, string, string, bool, string);
		string get_name();
		bool interact(vector<Item*>&,vector<Item>&);
		void get_description();
	private:
		string Name;
		string Interact;
		string Make;
		string Make_interact;
		string Make_description;
		bool Interact_need;
		string Interact_item;
		string Description;


};

#endif
