#include <iostream>
#include <limits>
#include <string>
#include <regex>

using namespace std;

/* Gathers input from the player and validates the data
*/
int get_input()
{
	int choice; //final input to be passed back
	string Input; //initial input
	regex Pattern("^[0123456789]*$") ; // to verify input is an int


	//get input
	cout << ">";
	getline(cin,Input);

	//Makes sure input is not empty
	while (Input.length() == 0)
	{
		cout << endl << "Please enter an integer value" << endl << ">";
		getline(cin, Input);
	}

	//loops so that on return there is always a valid value
	while (1)
	{

		//Verify that the value entered was an int
		if (regex_match(Input, Pattern))
		{
			//convert string to int
			//assign int to our return variable, choice
			choice = stoi(Input);

			//exit loop
			break;
		}
		else { //Prompts for new input because it did not meet criteria

			//retry getting input
			cout << endl << "Please enter an integer value" << endl << ">";
			getline(cin, Input);
			while (Input.length() == 0)
			{
				cout << endl << "Please enter an integer value" << endl << ">";
				getline(cin, Input);
			}
		}
	}
	

	return choice;
}