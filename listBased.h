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
			string checkName;
			bool there = false;

			//Find out the name of the location they are looking for
			cout << "Enter name of the city to be searched:";
			cin >> checkName;
			cout << endl;
			
			//Check to see if the list is there
			CityList* check = head;
			while(check != NULL && !there)
			{
				if(check->name == checkName)
				{
					//If the location is there, print its coordinates
					there = true;
					cout << check->name << ", ("
						<< check->latitude << ","
						<< check->longitude << ")" << endl << endl;
				}
				
				check = check->next;
			}
			
			if(!there)
			{
				cout << "No such record exists in the existing data set." << endl << endl;
			}
		}
		
		void searchCoordinate()
		{
			double lat;
			double lon;
			bool there = false;

			//Find out the coordinates of the location they are looking for
			cout << "Enter name of the latitude to be searched:";
			cin >> lat;
			cout << "Enter name of the longitude to be searched:";
			cin >> lon;
			cout << endl;
			
			//Check to see if the list is there
			CityList* check = head;
			while(check != NULL && !there)
			{
				if(check->latitude == lat && check->longitude == lon)
				{
					//If the location is there, print its coordinates
					there = true;
					cout << check->name << ", ("
						<< check->latitude << ","
						<< check->longitude << ")" << endl << endl;
				}
				
				check = check->next;
			}
			
			if(!there)
			{
				cout << "No such record exists in the existing data set." << endl << endl;
			}
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

