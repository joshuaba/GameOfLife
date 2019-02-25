#include <iostream>
#include <string>
#include <fstream>
#include "GameOfLife.h"

using namespace std;

void GameOfLife::populateGenZeroFromFile()
{

	cout << "Please provide the name of the file from which to read: " << endl;
	string inputFile;
	cin >> inputFile;

	ifstream inputStream;
	inputStream.open(inputFile);

	int numOfRows, numOfColumns;

	inputStream >> numOfRows >> numOfColumns;

	typedef int* myPtr;

	myPtr *a = new myPtr[numOfRows];
	for (int i = 0; i < numOfRows; ++i)
	{
		a[i] = new int[numOfColumns];
	}

	//int cellsToPopulate = numOfRows * numOfColumns;
	//int cellsPopuated = 0;

	for (int i = 0; i < numOfRows; ++i)
	{

		string thisLine;

		if(!inputStream.eof())
		{
			getline(inputStream, thisLine);
		}
		else
		{
			cout << "File has ended!" << endl;
		}

		for (int j = 0; j < numOfColumns; ++j)
		{

			for(int s = 0; s < thisLine.size(); ++s)
			{
				if(thisLine[s] == 'X')
				{
					a[0][j] = 1;
				}
				else
				{
					a[0][j] = 0;
				}
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
}
