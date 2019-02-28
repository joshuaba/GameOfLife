#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include "GameOfLife.h"

using namespace std;

void GameOfLife::populateGenZeroFromFile()
{

	cout << "Please provide the name of the file from which to read: " << endl;
	string inputFile;
	cin >> inputFile;

	ifstream inputStream;
	inputStream.open(inputFile);

	if(inputStream.fail())
	{
		cout << "Error opening the input file. Either the file does not exist or cannot be found!" << endl;
		exit(1);
	}

	int numOfRows, numOfColumns;

	inputStream >> numOfRows >> numOfColumns;

	string placeholder;
	getline(inputStream, placeholder); //to move on to the next line

	typedef int* myPtr;

	myPtr *a = new myPtr[numOfRows];

	for (int i = 0; i < numOfRows; ++i)
	{
		a[i] = new int[numOfColumns];
	}

	int i = 0;

	string thisLine;

	for (int i = 0; i < numOfRows; ++i)
	{
		getline(inputStream,thisLine);

		cout << "The current line being read is: " << thisLine << endl;

		for(int j = 0; j < numOfColumns; ++j)
		{
			if(thisLine[j] == 'X' || thisLine[j] == 'x')
			{
				a[i][j] = 1;
			}
			else
			{
				a[i][j] = 0;
			}
		}
	}


	for (int i = 0; i < numOfRows; ++i)
	{
		for (int j = 0; j < numOfColumns; ++j)
		{
			cout << a[i][j];
		}
		cout << endl;
	}

	inputStream.close();
}

void GameOfLife::randomizeWorld(int numRows, int numColumns)
{
	typedef char* myPtr;

	myPtr *a = new myPtr[numRows];

	for (int i = 0; i < numRows; ++i)
	{
		a[i] = new char[numColumns];
	}

	//populate the cells of the "world"
	for (int i = 0; i < numRows; ++i)
	{
		for (int j = 0; j < numColumns; ++j)
		{
			int randNum = rand ( );

			if(randNum % 2 == 0)
			{
				a[i][j] = 'X';
			}
			else
			{
				a[i][j] = '-';
			}
		}
	}

	for (int i = 0; i < numRows; ++i)
	{
		for (int j = 0; j < numColumns; ++j)
		{
			cout <<  a[i][j];
		}
		cout <<  endl;
	}
}
