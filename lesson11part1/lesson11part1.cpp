#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;

const int MAX_SIZE = 21;

int readSquare(int square[MAX_SIZE][MAX_SIZE], string inputFileName);
void displaySquare(int square[MAX_SIZE][MAX_SIZE], int size);
bool validateSquare(const int square[MAX_SIZE][MAX_SIZE], int size);
int readSquare(int square[MAX_SIZE][MAX_SIZE], string inputFileName)
{

	fstream file;
	int size;

	file.open(inputFileName);
	
	if (file.fail())
	{
		cout << endl << "File \"" << inputFileName << "\" could not be opened" << endl;
		exit(0);
	}
	else
	{
		file >> size;
		for (int x = 0; x < size; x++)
		{
			for (int y = 0; y < size; y++)
			{
				file >> square[x][y];
			}
		}

		file.close();
	}
	return size;
}
void displaySquare(int square[MAX_SIZE][MAX_SIZE], int size)
{

	cout << endl << "Magic square" << endl;
	for (int x = 0; x < size; x++)
	{
		for (int y = 0; y < size; y++)
		{
			cout << square[x][y];
			cout << " ";
		}
		cout << endl;
	}
}


bool validateSquare(const int square[MAX_SIZE][MAX_SIZE], int size)
{

	int n = 1;
	int temp = 0;

	int val = size * (size * size + 1) / 2;

	for (int x = 0; x < size; x++)
	{
		for (int y = 0; y < size; y++)
		{
			if (square[x][y] < 1 && square[x][y] > val)
				return false;
		}
	}


	for (int x = 0; x < size * size; x++)
	{
		temp = 0;
		for (int y = 0; y < size; y++)
		{
			for (int z = 0; z < size; z++)
			{
				if (square[y][z] == n)
				{
					temp = 1;
				}
			}
		}
		if (temp == 0)
		{
			return false;
		}
		else
		{
			n++;
		}
	}
	int sumDiagonal[2], sumCol = 0, sumRow = 0;

	int* rowSum = new int[size];
	int* colSum = new int[size];

	for (int x = 0; x < size; x++)
	{
		sumRow = 0;
		for (int y = 0; y < size; y++)
		{
			sumRow += square[x][y];
			rowSum[x] = sumRow;
		}
	}


	for (int x = 0; x < size; x++)
	{
		sumCol = 0;
		for (int y = 0; y < size; y++)
		{
			sumCol += square[y][x];
			colSum[x] = sumCol;
		}
	}
	sumDiagonal[0] = 0;
	for (int x = 0; x < size; x++)
	{
		sumDiagonal[0] += square[x][x];
	}

	sumDiagonal[1] = 0;
	for (int y = 0; y < size; y++)
	{
		sumDiagonal[1] += square[y][size - 1 - y];
	}

	bool value = true;
	int sum = rowSum[0];
	for (int x = 1; x < size; x++)
	{
		value = value && (sum == rowSum[x]);
	}
	for (int x = 0; x < size; x++)
	{
		value = value && (sum == colSum[x]);
	}
	for (int x = 0; x < 2; x++)
	{
		value = value && (sum == sumDiagonal[x]);
	}

	delete[] rowSum;
	delete[] colSum;

	if (value)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{

	int square[MAX_SIZE][MAX_SIZE];

	string inputFileName;


	cout << "Enter input file name";
	cin >> inputFileName;

	int size = readSquare(square, inputFileName);
	displaySquare(square, size);

	if (validateSquare(square, size))
	{
		cout << endl << "Valid magic square" << endl;
	}
	else
	{
		cout << endl << "Invalid magic square" << endl;
	}

	return 0;
}
