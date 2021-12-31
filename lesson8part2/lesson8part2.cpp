/*
* Omar Khan
* 11/15/2021
* Calculate Future Value
*/
#include <cmath>
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

double readfutureValue()
{
	double futureValue;
	cout << "Enter future value" << endl; cin >> futureValue;
	while (futureValue <= 0)
	{
		cout << "The future value must be greater than zero" << endl;
		cout << "Enter future value" << endl; cin >> futureValue;
	}
	return futureValue;
}

double readinterestRate()
{
	double interestRate;
	cout << "Enter annual interest rate" << endl; cin >> interestRate;
	while (interestRate <= 0)
	{
		cout << "The annual interest rate must be greater than zero" << endl;
		cout << "Enter annual interest rate" << endl; cin >> interestRate;
	}
	interestRate /= (float)10.00;
	interestRate *= 10;
	return interestRate;
}

int readnumberYears()
{
	int numberYears;
	cout << "Enter number of years" << endl; cin >> numberYears;
	while (numberYears <= 0)
	{
		cout << "The number of years must be greater than zero" << endl;
		cout << "Enter number of years" << endl; cin >> numberYears;
	}
	return numberYears;
}
double presentValue(double futureValue, double interestRate, int numberYears)
{
	//double rate = interestRate / 100.0;
	double presentValue = (futureValue / (pow((1 + interestRate), numberYears)));
	return presentValue;
}

void displayValues(double presentValue, double futureValue, double interestRate, int numberYears)
{
	cout << "Present value: $" << showpoint << fixed << setprecision(2) << presentValue << endl;
	cout << "Future value: $" << showpoint << fixed << setprecision(2) << futureValue << endl;
	cout << "Annual interest rate: " << showpoint << fixed << setprecision(3) << interestRate  << "%" << endl;
	cout << "Years: " << numberYears << endl;
}

int main()
{
		double  futureValue  = readfutureValue();

		double interestRate = readinterestRate();

		int		 numberYears = readnumberYears();
		
		double presentValues = presentValue(futureValue, interestRate / 100, numberYears);
			
		displayValues(presentValues, futureValue, interestRate, numberYears);
		
		return EXIT_SUCCESS;
}