#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

struct CityList
{
	string name;
	double latitude;
	double longitude;
	CityList* next;
};

class listBased
{
	private:
		CityList head;
	
	public:
		listBased()
		{
			head.next = NULL;
		}
		
		void insert()
		{
		
		}
		
		void searchName()
		{
		
		}
		
		void searchCoordinate()
		{
		
		}
		
		void deleteName()
		{
		
		}
		
		void deleteCoordinate()
		{
		
		}
		
		void printDistance()
		{
		
		}
		
		void printAll()
		{
		
		}
};

#endif

