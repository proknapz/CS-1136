/* Omar Khan
 * 11/15/2021
 * Lesson7part2
 * This program reads files contain number that will be computed into a average 
 * of all numbers from 0 to 150 (inclusive) and creates a file for all numbers
 * not in the given range
 */



#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;


int main()
{
	string s;
	cout << "Enter input file name" << endl;
	cin >> s;

	ifstream inputFile;
	inputFile.open(s);
	if (inputFile.fail())
	{
		cout << "File " << "\"" << s << "\"" << " could not be opened" << endl;
		return -1;
	}
	cout << "Reading from file " << "\"" << s << "\"" << endl;
	double float1;

	float sum = 0;
	int	count = 0,
		invalid = 0,
		valid = 0;

	ofstream outputFile;
	outputFile.open("invalid-values.txt");

	while (inputFile >> float1)
	{
		if ((float1 >= 0 && float1 <= 105))
		{
			count++;
			valid++;
			sum = sum + float1;
		}
		else
		{
			outputFile << fixed << setprecision(5) << float1 << endl;
			invalid++;
			count++;
		}

	}
	cout << "Total values: " << count << endl;
	cout << "Invalid values: " << invalid << endl;
	cout << "Valid values: " << valid << endl;
	float average = sum / valid;
	if (average != average)
		cout << "An average cannot be calculated" << endl;
	else
		cout << "Average of valid values: " << showpoint << fixed << setprecision(4) << (sum) / float(valid) << endl;

}