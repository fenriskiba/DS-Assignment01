#include <iostream>
#include <cmath>
#include <cstdlib>
#include "arrayBased.h"
#include "listBased.h"

using namespace std;

arrayBased arrayImp;
listBased listImp;

bool displayPrompt();

int main()
{
	bool running = true;
	
	while(running)
	{
		running = displayPrompt();
	}

	return 0;
}

void displayPrompt()
{
	int impOp;
	char operOp;
	
	//Display initial Prompt
	cout << "*************************************" << endl
		<< "Implementation Options:" << endl
		<< "A.Use an array-based list implementation" << endl
		<< "B.Use a linked-list implementation" << endl << endl
		<< "Operation Options:" << endl
		<< "1. Insert a record" << endl
		<< "2. Search for a record by name" << endl
		<< "3. Search for a record by coordinate" << endl
		<< "4. Delete a record by name" << endl
		<< "5. Delete a record by coordinate" << endl
		<< "6. Print records within a given distance of a specified location" << endl
		<< "7. Print all records" << endl
		<< "8. Exit" << endl << endl;
	
	//Request input
	cout << "Enter your implemenation option:";
	cin >> impOp;
	cout << "Enter your operation option:";
	cin >> operOp;
	cout << endl;
	
	//Exit if necessary
	if(impOp == 8)
	{
		return false;
	}
	else if(toupper(operOp) == 'A')
	{
		//Go to the appropriate function withing the array implementation
		switch(impOp)
		{		
			case 1:
				//Insert a record
				arrayImp.insert();
				break;
			case 2:
				//Search for a record by name
				arrayImp.searchName();
				break;
			case 3:
				//Search for a record by coordinate
				arrayImp.seachCoordinate();
				break;
			case 4:
				//Delete a record by name
				arrayImp.deleteName();
				break;
			case 5:
				//Delete a record by coordinate
				arrayImp.deleteCoordinate();
				break;
			case 6:
				//Print records within a given distance of a specified location
				arrayImp.printDistance();
				break;
			case 7:
				//Print all records
				arrayImp.printAll();
				break;
			default:
				cout << "Invalid Input\n Please try again\n\n";
		}
	}
	else if(toupper(operOp) == 'B')
	{
		//Go to the appropriate function withing the list implementation
		switch(impOp)
		{
			case 1:
				//Insert a record
				listImp.insert();
				break;
			case 2:
				//Search for a record by name
				listImp.searchName();
				break;
			case 3:
				//Search for a record by coordinate
				listImp.searchCoordinate();
				break;
			case 4:
				//Delete a record by name
				listImp.deleteName();
				break;
			case 5:
				//Delete a record by coordinate
				listImp.deleteCoordinate();
				break;
			case 6:
				//Print records within a given distance of a specified location
				listImp.printDistance();
				break;
			case 7:
				//Print all records
				listImp.printAll();
				break;
			default:
				cout << "Invalid Input\n Please try again\n\n";
		}
	}
	else
	{
		cout << "Invalid Input\n Please try again\n\n";
	}
	
	return true;
}

