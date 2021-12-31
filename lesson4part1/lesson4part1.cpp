/*
* Omar Khan
* 10/18/2021
* This program will take mass enter and convert to weight with acceleration times mass according to Earth, Moon, And Venus
*/


#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

const double earth = 9.81;
const double moon = 1.62;
const double venus = 8.87;

int main()
{

	double mass;

	cout << fixed << setprecision(4);
	cout << "Enter the mass in kg" << endl;
	cin >> mass;
	if (mass > 0) {
		cout << "The mass is " << mass << " kg" << setw(13) << endl;
		cout << "Location    Weight (N)" << endl;
	    double earthWeight = mass * earth;
		double moonWeight  = mass * moon;
		double venusWeight = mass * venus;
		cout << "Earth       " << setw(10) << fixed << setprecision(4) << right << earthWeight << endl;
		cout << "Moon       "  << setw(11) << fixed << setprecision(4) << right << moonWeight  << endl;
		cout << "Venus "       << setw(16) << fixed << setprecision(4) << right << venusWeight << endl;
	
		if (earthWeight >= 1500)
		{
			cout << "The object is heavy" << endl;
		}
		else if (earthWeight < 5)
		{
			cout << "The object is light" << endl;
		}
	}
	else 
	{
		cout << "The mass is " << showpoint << fixed << setprecision(4) << mass << " kg" << endl;
		cout << "The mass must be greater than zero" << endl;

	}

	return 0;
}