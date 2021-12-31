/*
* Omar Khan
* 10/23/2021
* This program will take the users input of 1-3 and display the distance travels over a time period
*/


#include <iostream>
#include <iomanip>
#include <string>

using namespace std;


int main()
{
	unsigned
		menuChoice = 0;

	const unsigned int
		airChoice   = 1,
		waterChoice = 2,
		steelChoice = 3;

	double
		airSpeed   = 1100,
		waterSpeed = 4900,
		steelSpeed = 16400;

	double distance = 0;
	cout << "Select the medium that sound is traveling through:" << endl;
	cout << "1 Air"   << endl;
	cout << "2 Water" << endl;
	cout << "3 Steel" << endl;
	cin >> menuChoice; 
	switch (menuChoice)
	{
	case airChoice: 
		cout << "Enter distance (in feet)" << endl;
		cin >> distance;
		if (distance <= 0) {
			cout << "The distance must be greater than zero" << endl;
			break;
		}
		cout << "Air: " << showpoint << fixed << setprecision(4) << distance << " ft" << endl;
		cout << "Traveled for " << showpoint << fixed << setprecision(4) << distance / airSpeed << " seconds" << endl;
		break;

	case waterChoice:
		cout << "Enter distance (in feet)" << endl;
		cin >> distance;
		if (distance <= 0) {
			cout << "The distance must be greater than zero" << endl;
			break;
		}
		cout << "Water: " << showpoint << fixed << setprecision(4) << distance << " ft" << endl;
		cout << "Traveled for " << showpoint << fixed << setprecision(4) << distance / waterSpeed << " seconds" << endl;
		break;

	case steelChoice:
		cout << "Enter distance (in feet)" << endl;
		cin >> distance;
		if (distance <= 0) {
			cout << "The distance must be greater than zero" << endl;
			break;
		}
		cout << "Steel: " << showpoint << fixed << setprecision(4) << distance << " ft" << endl;
		cout << "Traveled for " << showpoint << fixed << setprecision(4) << distance / steelSpeed << " seconds" << endl;
		break;

	default:
		cout << "The menu value is invalid. Please run the program again." << endl;




	}

}