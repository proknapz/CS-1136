/*
* Omar Khan
* 10/23/2021
* This program will take the users input from 1-4 and and time entered to calculate distance traveled in that time 
*/


#include <iostream>
#include <iomanip>
#include <string>

using namespace std;



int main()
{
	unsigned
		menuValue = 0;

	unsigned int
		carbonDioxideChoice = 1,
		airChoice = 2,
		heliumChoice = 3,
		hydrogenChoice = 4;

	

	double
		carbonDioxideSpeed = 258.0,
		airSpeed = 331.5,
		heliumSpeed = 972.0,
		hydrogenSpeed = 1270.0,
		time = 0;

	cout << "Select the medium that sound is traveling through:" << endl;
	cout << "1 Carbon Dioxide" << endl;
	cout << "2 Air" << endl;
	cout << "3 Helium" << endl;
	cout << "4 Hydrogen" << endl;
	cin >> menuValue;
	if (menuValue == carbonDioxideChoice) {
		cout << "Enter time (in seconds)" << endl;
			cin >> time;
			if (time < 0 || time >= 30) {
					cout << "The time must be between 0.000 and 30.000 (inclusive)" << endl;
					return 0;
				}
				cout << "Carbon Dioxide: " << showpoint << fixed << setprecision(3) << time << " seconds" << endl;
				cout << "Traveled " << showpoint << fixed << setprecision(4) << time * carbonDioxideSpeed << " meters" << endl;
	}	
	else if (menuValue == airChoice) {
		cout << "Enter time (in seconds)" << endl;
				cin >> time;
				if (time < 0 || time >= 30) {
					cout << "The time must be between 0.000 and 30.000 (inclusive)" << endl;
					return 0;
				}
				cout << "Air: " << showpoint << fixed << setprecision(3) << time << " seconds" << endl;
				cout << "Traveled " << showpoint << fixed << setprecision(4) << time * airSpeed << " meters" << endl;

	}
	else if (menuValue == heliumChoice) {
		cout << "Enter time (in seconds)" << endl;
			cin >> time;
			if (time < 0 || time >= 30) {
				cout << "The time must be between 0.000 and 30.000 (inclusive)" << endl;
				return 0;
			}
			cout << "Helium: " << showpoint << fixed << setprecision(3) << time << " seconds" << endl;
			cout << "Traveled " << showpoint << fixed << setprecision(4) << time * heliumSpeed << " meters" << endl;
	}
	else if (menuValue == hydrogenChoice) {
		cout << "Enter time (in seconds)" << endl;
			cin >> time;
			if (time < 0 || time >= 30) {
				cout << "The time must be between 0.000 and 30.000 (inclusive)" << endl;
					return 0;
			}
			cout << "Hydrogen: " << showpoint << fixed << setprecision(3) << time << " seconds" << endl;
			cout << "Traveled " << showpoint << fixed << setprecision(4) << time * hydrogenSpeed << " meters" << endl;

	}
	else {
		cout << "The menu value is invalid. Please run the program again." << endl;
	}
	
}