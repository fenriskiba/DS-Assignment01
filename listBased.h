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
		CityList* head;
		
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
			head = NULL;
		}
		
		void insert()
		{
			string newName;
			double lat;
			double lon;
			bool there = false;

			//Collect values
			cout << "Enter name of the city:";
			cin >> newName;
			cout << "Enter x coordinate of the city:";
			cin >> lat;
			cout << "Enter y coordinate of the city:";
			cin >> lon;
			
			//Check if the city is already there
			CityList* check = head;
			while(check != NULL && !there)
			{
				if(check->name == newName)
					there = true;
				check = check->next;
			}
			
			if(there)
			{
				cout << endl << "No need to insert again, "
					<< "as this record exists in the existing data set." << endl;
			}
			else
			{
				//If the city isn't there yet put it at the top of the list
				CityList* newCity = new CityList;
				newCity->name = newName;
				newCity->latitude = lat;
				newCity->longitude = lon;
				newCity->next = head;
				head = newCity;
				cout << "Record inserted successfully." << endl << endl;
			}
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

