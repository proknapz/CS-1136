
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

int read(unsigned char answersArray[], string inputfilename)
{
	const unsigned MAX_ARRAY_SIZE = 30;
	const int      FILE_READ_ERROR = -1;

	ifstream inputAnswersStream(inputfilename);

	if (inputAnswersStream.fail())
	{
		return (FILE_READ_ERROR);
	}
	unsigned inputCount = 0;
	while (inputAnswersStream >> answersArray[inputCount])
	{
		++inputCount;
	}

	if (inputCount > MAX_ARRAY_SIZE)
	{
		return (MAX_ARRAY_SIZE);
	}

	return inputCount;
}

void workdisplay(unsigned char studentAnswersArray[], unsigned char correctAnswersArray[], unsigned arrayCount)
{
	unsigned notCorrect = 0;
	unsigned noCorrect = 0;
	double  grade = 0;
	for (unsigned int x = 0; x <= arrayCount; x++)
	{
		if (studentAnswersArray[x] != correctAnswersArray[x])
		{
			cout << "Question " << x + 1 << " has incorrect answer \'" << studentAnswersArray[x] << "\', the correct answer is \'" << correctAnswersArray[x] << "\'" << endl;
			notCorrect++;
		}
	}
	//cout << correctAnswers++ << endl;
	//cout << arrayCount << endl;
	noCorrect = arrayCount - notCorrect;
	grade = (noCorrect / (float)arrayCount) * 100;
	cout << notCorrect << " questions were missed out of " << arrayCount << endl; // Add number of question
	cout << "The student grade is " << setprecision(1) << fixed << showpoint << grade << "%" << endl;
	if (grade < 70)
		cout << "The student failed" << endl;
	else if (grade >= 70)
		cout << "The student passed" << endl;
}


int main() {

	const unsigned MAX_ARRAY_SIZE = 30;
	const int      FILE_READ_ERROR = -1;

	string studentAnswersFileName;
	string correctAnswersFileName;

	int studentAnswerCount;
	int correctAnswerCount;

	unsigned char studentAnswersArray[MAX_ARRAY_SIZE] = { 0 };
	unsigned char correctAnswersArray[MAX_ARRAY_SIZE] = { 0 };

	cout << "Enter student answers file name" << endl;
	cin >> studentAnswersFileName;
	studentAnswerCount = read(studentAnswersArray, studentAnswersFileName);
	if (studentAnswerCount != FILE_READ_ERROR)
	{
		cout << "Enter correct answer file name" << endl;
		cin >> correctAnswersFileName;
		correctAnswerCount = read(correctAnswersArray, correctAnswersFileName);
		if (correctAnswerCount != FILE_READ_ERROR)
		{
			if (studentAnswerCount != correctAnswerCount) {
				cout << "The student answers file has " << studentAnswerCount
					<< " entries and the correct answers file has "
					<< correctAnswerCount << " entries" << endl
					<< "Grading cannot be done if they are not the same" << endl;
				return (EXIT_FAILURE);
			}
			if ((studentAnswerCount == 0) && (correctAnswerCount == 0)) {
				cout << "The number of student answers and correct answers are both "
					<< studentAnswerCount << endl << "No grade can be calculated" << endl;
				return (EXIT_SUCCESS);
			}
			studentAnswerCount = read(studentAnswersArray, studentAnswersFileName);
			workdisplay(studentAnswersArray, correctAnswersArray, studentAnswerCount);
			return EXIT_FAILURE;
		}
		else
		{
			cout << "File " << "\"" << correctAnswersFileName << "\"" << " could not be opened" << endl;
		}
	}
	else
	{
		cout << "File " << "\"" << studentAnswersFileName << "\"" << " could not be opened" << endl;
		return EXIT_FAILURE;

	}

	return EXIT_SUCCESS;

}


