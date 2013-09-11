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
		int len;
		
		bool alreadyThere(string checkName)
		{
			for(int index = 0; index < len; index++)
			{
				if(checkName == records[index].name)
					return true;
			}
			
			return false;
		}
	
	public:
		arrayBased()
		{
			len = 0;
		}
	
		void insert()
		{
			string newName;
			double lat;
			double lon;
			
			cout << "Enter name of the city: ";
			cin >> newName;
			cout << "Enter x coordinate of the city: ";
			cin >> lat;
			cout << "Enter y coordinate of the city: ";
			cin >> lon;
			cout << endl;
			
			bool there = alreadyThere(newName);
			
			if(there)
			{
				cout << "No need to insert again, "
					<< "as this record exists in the existing data set." << endl;
			}
			else
			{
				len++;
				City* temp = new City[len];
				
				for(int index = 0; index < (len - 1); index++)
				{
					temp[index] = records[index];
				}
				
				temp[len - 1].name = newName;
				temp[len - 1].latitude = lat;
				temp[len - 1].longitude = lon;
				
				delete [] records;
				records = temp;
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

