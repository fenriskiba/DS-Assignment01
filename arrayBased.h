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
		
		double getDistance(City one, City two)
		{
			//ARCCOS[ SIN(LAT1)*SIN(LAT2) + COS(LAT1)*COS(LAT2)*COS(LONG2-LONG1) ]
			double result = acos( sin(one.latitude) * sin(two.latitude) +
									cos(one.latitude) * cos(two.latitude) * 
									cos(two.longitude - one.longitude) ) *	3963.191;
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
			bool there = false;
			
			//Collect values
			cout << "Enter name of the city:";
			cin >> newName;
			cout << "Enter x coordinate of the city:";
			cin >> lat;
			cout << "Enter y coordinate of the city:";
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
			cout << "Enter name of the city to be searched:";
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
			cout << "Enter name of the latitude to be searched:";
			cin >> lat;
			cout << "Enter name of the longitude to be searched:";
			cin >> lon;
			cout << endl;
			
			for(int index = 0; index < len && !there; index++)
			{
				//If it's in the list print its coordinates
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
			string delName;
			int delIndex;
			bool there = false;
			
			//Find out the name of the location to be deleted
			cout << "Enter name of the city to be deleted:";
			cin >> delName;
			cout << endl;
			
			for(int index = 0; index < len && !there; index++)
			{
				//If its in the list mark it for deletion
				if(delName == records[index].name)
				{
					there = true;
					delIndex = index;
				}	
			}
			
			if(!there)
			{
				cout << "No such record exists in the existing data set." << endl << endl;
			}
			else
			{
				//Delete the location from records
				len--;
				int newIndex = 0;
				City* temp = new City[len];
				
				for(int index = 0; index < (len + 1); index++)
				{
					if(index != delIndex)
					{
						temp[newIndex] = records[index];
						newIndex++;
					}
				}
				
				delete [] records;
				records = temp;
				
				cout << "Deleted successfully." << endl << endl;
			}
		}
		
		void deleteCoordinate()
		{
			double delLat;
			double delLon;
			int delIndex;
			bool there = false;
			
			//Find out the coordinates of the location to be deleted
			cout << "Enter latitude of the city to be deleted:";
			cin >> delLat;
			cout << "Enter longitude of the city to be deleted:";
			cin >> delLon;
			cout << endl;
			
			for(int index = 0; index < len && !there; index++)
			{
				//If its in the list mark it for deletion
				if(delLat == records[index].latitude && delLon == records[index].longitude)
				{
					there = true;
					delIndex = index;
				}	
			}
			
			if(!there)
			{
				cout << "No such record exists in the existing data set." << endl << endl;
			}
			else
			{
				len--;
				int newIndex = 0;
				City* temp = new City[len];
				
				for(int index = 0; index < (len + 1); index++)
				{
					if(index != delIndex)
					{
						temp[newIndex] = records[index];
						newIndex++;
					}
				}
				
				delete [] records;
				records = temp;
				
				cout << "Deleted successfully." << endl << endl;
			}
		}
		
		void printDistance()
		{
			bool there = false;
			string location;
			int locIndex;
			double distance;
			
			//Find the name of the location and the distance from it
			cout << "Enter name of the specified location:";
			cin >> location;
			cout << "Enter distance:";
			cin >> distance;
			cout << endl;
			
			//Find the index of the location
			for(int index = 0; index < len && !there; index++)
			{
				//If its in the list mark it
				if(location == records[index].name)
				{
					there = true;
					locIndex = index;
				}	
			}
			
			if(there)
			{
				//Print all the locations within a certain distance
				for(int index= 0; index < len; index++)
				{
					if(index != locIndex && 
						getDistance(records[locIndex], records[index]) <= distance)
					{
						cout << records[index].name << ", ("
							<< records[index].latitude << ","
							<< records[index].longitude << ")" << endl << endl;
					}
				}
			}
			else
			{
				cout << "No such record exists in the existing data set." << endl << endl;
			}
		}
		
		void printAll()
		{
			//Print all the locations
			for(int index= 0; index < len; index++)
			{
				cout << records[index].name << ", ("
					<< records[index].latitude << ","
					<< records[index].longitude << ")" << endl << endl;
			}
		}
};

#endif

