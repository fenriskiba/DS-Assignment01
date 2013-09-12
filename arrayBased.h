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
			bool there = false;
			
			//Collect values
			cout << "Enter name of the city: ";
			cin >> newName;
			cout << "Enter x coordinate of the city: ";
			cin >> lat;
			cout << "Enter y coordinate of the city: ";
			cin >> lon;
			
			//Check if the location is already there
			for(int index = 0; index < len; index++)
			{
				if(newName == records[index].name)
					there =  true;
			}			
			
			if(there)
			{
				cout << endl << "No need to insert again, "
					<< "as this record exists in the existing data set." << endl;
			}
			else
			{
				//If the location isn't input yet, place the new value into records
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
				
				cout << "Record inserted successfully." << endl << endl;
			}
		}
		
		void searchName()
		{
			string checkName;
			bool there = false;
			
			//Find out the name of the location they are looking for
			cout << "Enter name of the city to be searched: ";
			cin >> checkName;
			cout << endl;
			
			for(int index = 0; index < len && !there; index++)
			{
				//If its in the list print its coordinates
				if(checkName == records[index].name)
				{
					there = true;
					cout << records[index].name << ", ("
						<< records[index].latitude << ","
						<< records[index].longitude << ")" << endl << endl;
				}	
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
			cout << "Enter name of the latitude to be searched: ";
			cin >> lat;
			cout << "Enter name of the longitude to be searched: ";
			cin >> lon;
			cout << endl;
			
			for(int index = 0; index < len && !there; index++)
			{
				//If its in the list print its coordinates
				if(lat == records[index].latitude && lon == records[index].longitude)
				{
					there = true;
					cout << records[index].name << ", ("
						<< records[index].latitude << ","
						<< records[index].longitude << ")" << endl << endl;
				}	
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

