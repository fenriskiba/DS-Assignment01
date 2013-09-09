#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

struct City
{
	string name;
	double latitude;
	double longitude;
	City* next;
};

class listBased
{
	private:
		City head;
	
	public:
		City()
		{
			head.next = NULL;
		}
		
		void insert();
		void searchName(string);
		void searchCoordinate(double, double);
		void deleteName(string);
		void deleteCoordinate(double, double);
		void printDistance(string, double);
		void printAll();
};

#endif

