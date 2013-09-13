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
		
		double getDistance(CityList one, CityList two)
		{
			//Return the distance between the two locations
			double result = acos( sin(one.latitude) * sin(two.latitude) +
									cos(one.latitude) * cos(two.latitude) * 
									cos(two.longitude - one.longitude) ) *	3963.191;
			return abs(result);
		}
	
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

