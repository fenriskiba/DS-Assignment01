#include <iostream>
#include <cmath>
#include <cstdlib>
#include "arrayBased.h"
#include "listBased.h"

using namespace std;

void displayPrompt();

int main()
{
	bool running = true;
	
	while(running)
	{
		displayPrompt();
	}

	return 0;
}

void displayPrompt()
{
	//Display basic Prompt
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
		<< "8. Exit" << endl;	
}

