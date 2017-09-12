// Lab01.cpp
// Robert Randolph
// COSC
// September 11th, 2017
// Assuming text files have at least 4 numbers and only white space.

#include<iostream>
using std::cout;
using std::cin;
using std::endl;
#include<fstream>
using std::ifstream;
#include<string>
using std::string;

int main()
{
	ifstream inFile;
	string fileInput;
	int numberCount(0);
	double firstNumber, secondNumber, secondLastNumber, lastNumber, tmp;

	// Getting filename from user.
	cout << "Give me a file:";
	cin >> fileInput;

	// Opening file.
	inFile.open(fileInput);

	// Checking if file was opened.
	if (inFile.is_open())
	{
		cout << "Opened file." << endl;

		// Getting first and second numbers.
		inFile >> firstNumber;
		inFile >> secondNumber;
		// Updating number count.
		numberCount = 2;

		// Getting number count, second-to-last number, and last number.
		while (inFile >> lastNumber)	// Get the next number.
		{
			numberCount++;	// Update number count.

			// Check to see if there is another valid number, and then get it.
			// Otherwise update second-to-last number to it's appropriate value.
			if(inFile >> tmp)
			{
				// If there is a valid number, update number count.
				numberCount++;
				// LastNumber is no longer the last number so cycle the numbers so it is now the second-to-last number.
				secondLastNumber = lastNumber;
				// tmp is now the last number so updating the lastNumber to actually be the last number.
				lastNumber = tmp;
			}
			// At this point the lastNumber is correct but the secondLastNumber isn't.
			// However tmp is now holding the second-to-last number.
			else
			{
				secondLastNumber = tmp; // Updating second-to-last number to it's appropriate value.
			}
		}

		// Outputing results.
		cout << "Amount of numbers: " << numberCount << endl
			<< "First Number: " << firstNumber << endl
			<< "Second Number: " << secondNumber << endl
			<< "Second to last Number: " << secondLastNumber << endl
			<< "Last Number: " << lastNumber << endl;

		// Closing file.
		inFile.close();
	}
	else // If file wasn't succesfully opened.
	{
		cout << "Couldn't open file.";	// Give error message and do nothing else if file wasn't opened.
	}

	return 0;
}