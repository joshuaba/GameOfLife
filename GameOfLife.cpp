#include <iostream>
#include <string>
#include <fstream>

#include "GameOfLife.h"

using namespace std;

GameOfLife::GameOfLife() //default constructor
{
	world0 = World(2,2,'C');
	world1 = World(2,2,'C');
	currentWorld = 0;
	wereNeighborsFound = false;
	wasWorldChanged = false;
}

GameOfLife::GameOfLife(char fromFile)
{
	if (fromFile == 'Y')
	{
		populateFirstWorldsFromFile();
	}
	currentWorld = 0;
}

GameOfLife::GameOfLife(int numRows, int numColumns, float popDensity, char theMode)
{
	randomizeFirstWorld(numRows, numColumns, popDensity, theMode);
	currentWorld = 0;
}

World GameOfLife::getWorld0()
{
	return world0;
}

World GameOfLife::getWorld1()
{
	return world1;
}

World GameOfLife::getSourceWorld()
{
	return sourceWorld;
}

World GameOfLife::getTargetWorld()
{
	return targetWorld;
}

void GameOfLife::populateFirstWorldsFromFile()
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

		cout << "Which mode would you like to run the program in? Type \'C\' for classic, \'D\' for doughnut, or \'M\' for mirror." << endl;

		char mode;

		cin >> mode;

		world0 = World(numOfRows, numOfColumns, mode);
		world1 = World(numOfRows, numOfColumns, mode);

		int i = 0;

		string thisLine;

		getline(inputStream, thisLine); //clear the buffer

		for (int i = 0; i < numOfRows; ++i)
		{
			getline(inputStream,thisLine);

			cout << "The current line being read is: " << thisLine << endl;

			for(int j = 0; j < numOfColumns; ++j)
			{
				if(thisLine[j] == 'X' || thisLine[j] == 'x')
				{
					world0.setCellValue(i,j,'X');
				}
				else
				{
					world0.setCellValue(i,j,'-');
				}
			}
		}

		inputStream.close();
}

void GameOfLife::randomizeFirstWorld(int numRows, int numColumns, float popDensity, char theMode)
{
	int totalCells = numRows * numColumns;

	int maxCellsToFill = totalCells * popDensity;

	int cellsFilled = 0;

	//a = new myPtr[numRows];

	world0 = World(numRows, numColumns, theMode);
	world1 = World(numRows, numColumns, theMode);

	//populate the cells of the "world"
	for (int i = 0; i < numRows; ++i)
	{
		for (int j = 0; j < numColumns; ++j)
		{
			int randNum = rand ( );

			if(randNum % 2 == 0 && cellsFilled <= maxCellsToFill)
			{
				world0.setCellValue(i,j,'X');
				cellsFilled++;
			}
			else
			{
				world0.setCellValue(i,j,'-');
			}
		}
	}
}

bool GameOfLife::getWasWorldChanged()
{
	return wasWorldChanged;
}

bool GameOfLife::getWereNeighborsFound()
{
	return wereNeighborsFound;
}

void GameOfLife::setWasWorldChanged(bool changed)
{
	wasWorldChanged = changed;
}

void GameOfLife::setWereNeighborsFound(bool found)
{
	wereNeighborsFound = found;
}

void GameOfLife::toggleWorlds()
{
	if (currentWorld == 0)
	{
		sourceWorld = world0;
		targetWorld = world1;
		currentWorld = 1;
	}
	else
	{
		sourceWorld = world1;
		targetWorld = world0;
		currentWorld = 0;
	}
	wasWorldChanged = false;
	wereNeighborsFound = false;
}
