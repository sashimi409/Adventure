#ifndef Setup
#define Setup
#include <string>
#include <vector>
#include "Room.h"
#include "Items.h"


void Make_doors(vector<Room>& , string , string );
void Make_Items(vector<Item>& ,vector<Room>& , string , string );
void Make_Objects(vector<Item>& ,vector<Room>& , string , string );
void intro();
void setup(vector<Room>& ,vector<Item>& );

#endif
