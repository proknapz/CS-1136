/*
* Omar Khan
* 10/28/2021
* This program will take in an lower and upper integer.
* Then it will convert the lower value to an character until it increments till the upper integer
*/
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
	//unsigned
	int upper;
	//unsigned
	int lower;

	cout << "Enter lower and upper values" << endl;
	cin >> lower;
	cin >> upper;
	while (!(lower >= 32 && upper <= 126) ^ !(lower < 126 && upper > 32))
	{
		cout << "Values must be in range 32 to 126 inclusive" << endl;
		cout << "Enter lower and upper values" << endl;
		cin >> lower;
		cin >> upper;
		continue;
	}

	cout << "Characters for ASCII values between " << lower << " and " << upper << endl;
	cout << "----+----+----+----+" << endl;
	int y = 0;
	for (int x = lower; x <= upper; x++)
	{
		char out = (char)lower;
		cout << out;
		if (lower == upper)
			break;
		if (y == 19) {
			cout << endl;
			y = -1;
		}
		y++;
		lower++;
	}

	cout << endl << "----+----+----+----+" << endl;







}