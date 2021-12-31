/*
* Omar Khan
* 11/15/2021
* Calculate Earth and Moon Distance
*/
#include <cmath>
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

double readSeconds()
{

	double seconds;
	cout << "Enter the time (in seconds)" << endl;
	cin >> seconds;
	return seconds;
}

double calculateEarthDistance(double seconds)
{
	const double EARTH_GRAVITY = 9.8;
	seconds = 0.5 * EARTH_GRAVITY * pow(seconds, 2);
		return seconds;
}

double calculateMoonDistance(double seconds)
{
	const double MOON_GRAVITY = 1.6;
	seconds = 0.5 * MOON_GRAVITY * pow(seconds, 2);
		return seconds;
}

void displayResults(double seconds, double earthDistance, double moonDistance)
{
	cout << fixed << "The object traveled " << setprecision(4) << earthDistance << " meters in " << setprecision(2) << seconds << " seconds on Earth" << endl;
	cout << fixed << "The object traveled " << setprecision(4) << moonDistance << " meters in " << setprecision(2) << seconds << " seconds on the Moon" << endl;
}


using namespace std;

int main()
{
	double seconds = 0, earthDistance = 0, moonDistance = 0;

	do
	{
		seconds = readSeconds();
		if (seconds == 0)
			break;
		else if (seconds < 0)
			cout << "The time must be zero or more" << endl;
		else
		{
			earthDistance = calculateEarthDistance(seconds);

			moonDistance  =  calculateMoonDistance(seconds);

			displayResults(seconds, earthDistance, moonDistance);

		}
	} while (true);


	return EXIT_SUCCESS;

}


