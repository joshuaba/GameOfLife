/*
 Created on: Feb 24, 2019
 Author: Joshua (Non-Admin)
*/

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include "GameOfLife.h"

using namespace std;

int main(int argc, char **argv)
{
	cout << "Would you like to provide a map file to simulate the program?" << endl;
	char userAnswer;
	cin >> userAnswer;

	GameOfLife simulation1;

	if(userAnswer == 'Y' || userAnswer == 'y')
	{

		simulation1.populateGenZeroFromFile();

		//cout << "Please provide the name of the file from which to read: ";
		//string inputFile;



		/*
		ifstream inputStream;
		inputStream.open(inputFile);

		int numOfRows, numOfColumns;

		inputStream >> numOfRows >> numOfColumns;
		*/
	}

	else
	{
		cout << "What are the dimensions of the \"world\"? Type in two integers, the first representing the number of rows and the second representing the number of columns" << endl;
		int numRows, numColumns;

		cin >> numRows >> numColumns;

		simulation1.randomizeWorld(numRows, numColumns);
	}
}



