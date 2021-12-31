/*
* Omar Khan
* 10/19/2021
* This program will convert seconds to the amount of days, hours, minutes, and seconds for a entered amount of seconds
*/


#include <iostream>
#include <iomanip>
#include <string>

using namespace std;


int main()
{

	long long seconds;
	int minutes;
	int hours;
	int days;

	

	cout << "Enter seconds" << endl;
	cin >> seconds;
	cout << "Total seconds: " << seconds << endl << endl;
	if (seconds > 0) {
		while (seconds > 0)
		{
			if (seconds > 86400)
			{
				days = seconds / 86400;
				cout << days << " day(s)" << endl;
				if ((seconds % 86400) == 0)
					break;
			}
			seconds = seconds % 86400;
			if (seconds > 3600)
			{
				hours = seconds / 3600;
				cout << hours << " hour(s)" << endl;
				if ((seconds % 3600) == 0)
					break;
			}
			seconds = seconds % 3600;
			if (seconds > 60)
			{
				minutes = seconds / 60;
				cout << minutes << " minute(s)" << endl;
				if ((seconds % 60) == 0)
					break;
			}
			
			seconds = seconds % 60;
			cout << seconds << " second(s)" << endl;
			 
			break;



		}
	}
	else 
	{
		cout << "Total seconds must be greater than zero" << endl;
	}
}