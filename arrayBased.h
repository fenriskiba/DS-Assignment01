#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

struct City
{
	string name;
	double latitude;
	double longitude;
};

class arrayBased
{
	private:
		City* records;
	
	public:
		void insert();
		void searchName();
		void searchCoordinate();
		void deleteName();
		void deleteCoordinate();
		void printDistance();
		void printAll();
};

#endif

