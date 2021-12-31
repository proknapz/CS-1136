/*
* Omar Khan
* 10/30/2021
* This program will take start and end values and convert them to celcius and kelvin until
* the start value is incremented until it reaches the endvalue
* 
*/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()

{

	double startValues;
	double endValues;
	double increment;
	double celsius;
	double kelvin;
	int i = 1;
	while (i == 1)
	{
		i = 0;
		cin >> startValues; 
		cin >> endValues; 
		cin >> increment;
		if (endValues < startValues || increment <= 0)
		{
			i = 1;
			cout << "Starting temperature must be <= ending temperature and increment must be > 0.0" << endl;
		}
	}
	cout << setw(18) << "Fahrenheit" << setw(18) << "Celsius" << setw(18) << "Kelvin";
	while (startValues <= endValues)
	{
		celsius = (startValues - 32) / 1.8;
		kelvin = celsius + 273.15;
		cout << endl;
		cout << fixed << setprecision(4) << setw(18) << startValues << setw(18) << celsius << setw(18) << kelvin;
		
		startValues += increment;
	}
	cout << endl;
	

}