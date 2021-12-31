/*
* Omar Khan
* 11/1/2021
* Sales Bar Chart
* This program will read files and generate file based on the data read with certains 
* to display on the console or text file
* 
*/



#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main() 
{
	string s = "";
	cout << "Enter input file name"; cin >> s; cout << endl;
	ifstream inputFile; //file get inputed into program
	inputFile.open(s);  //file from folder get open into program
	/*if (inputFile.fail())
	{
		cout << "File " << "\"" << s << "\"" << " could not be opened" << endl;
		return -1;
	}*/
	ofstream outputFile; //file get outputed from program
	outputFile.open("saleschart.txt");
	/*if (outputFile.fail())
	{
		cout << "Output file does not open" << endl;
		inputFile.close();
		return -1;
	}*/
	outputFile << "SALES BAR CHART" << endl; //acts as cout but in text file
	outputFile << "(Each * equals 5,000 dollars)" << endl; //acts as cout but in text file
	int STORE_NUM, SALES;
	while (inputFile >> STORE_NUM >> SALES) //access input file and check STORE_NUM and SALES
	{
		if (STORE_NUM > 0 && STORE_NUM < 100) //input file has stores of 0 < STORE_NUM < 100
		{
			if (SALES < 0) //access input for SALES < 0
				cout << "The sales value for store " << STORE_NUM << " is negative" << endl;
			else 
			{
				outputFile << "Store "  << setw(2) << STORE_NUM << ": ";//acts as cout but in text file
				SALES /= 5000;
				while (SALES > 0)
				{
					outputFile << "*";// acts as cout but in text file
					SALES--;
				}
				outputFile << endl;
			}
		}
		else 
		{
			cout << "The store number " << STORE_NUM << " is not valid" << endl;
		}
	}
	inputFile.close(); 
	outputFile.close();
	return 0;
}
