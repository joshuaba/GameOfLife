#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <vector>
#include "GameOfLife.h"
#include "Generations.h"
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

	Gen0World = Generations(numOfRows, numOfColumns);

	string placeholder;
	getline(inputStream, placeholder); //to move on to the next line

	//a = new myPtr[numOfRows];

	/*
	for (int i = 0; i < numOfRows; ++i)
	{
		a[i] = new char[numOfColumns];
	}
	*/
	//The above commented method was already done in the generation1 constructor called in line 30

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
				Gen0World.populateGeneration(i,j,'X');
				//a[i][j] = 'X';
			}
			else
			{
				Gen0World.populateGeneration(i,j,'-');
				//a[i][j] = '-';
			}
		}
	}


	/*
	for (int i = 0; i < numOfRows; ++i)
	{
		for (int j = 0; j < numOfColumns; ++j)
		{
			cout << a[i][j];
		}
		cout << endl;
	}
	*/

	inputStream.close();
}

void GameOfLife::randomizeWorld(int numRows, int numColumns, float popDensity)
{
	int totalCells = numRows * numColumns;

	int maxCellsToFill = totalCells * popDensity;

	int cellsFilled = 0;

	//a = new myPtr[numRows];

	Gen0World = Generations(numRows, numColumns);

	/*
	for (int i = 0; i < numRows; ++i)
	{
		a[i] = new char[numColumns];
	}
	*/

	//populate the cells of the "world"
	for (int i = 0; i < numRows; ++i)
	{
		for (int j = 0; j < numColumns; ++j)
		{
			int randNum = rand ( );

			if(randNum % 2 == 0 && cellsFilled <= maxCellsToFill)
			{
				Gen0World.populateGeneration(i,j,'X');
				//a[i][j] = 'X';
				cellsFilled++;
			}
			else
			{
				Gen0World.populateGeneration(i,j,'-');
			}
		}
	}

	/*
	for (int i = 0; i < numRows; ++i)
	{
		for (int j = 0; j < numColumns; ++j)
		{
			cout <<  a[i][j];
		}
		cout <<  endl;
	}
	*/

	myPtr currentGeneration = getGeneration();
}

void GameOfLife::populateNextGeneration(myPtr Gen0World, int numRows, int numColumns)
{
	int neighborsCounted = 0;

	while(neighborsCounted < 8)
	{
		//char neighbor =
	}
	for (int i = 0; i < numRows; ++i)
	{
		for(int j = 0; j < numColumns; ++j)
		{

		}
	}
}

myPtr GameOfLife::neighborArray(Generations generation, int rowIndex, int colIndex)
{
	myPtr arrayOfNeighbors = new char[10];

	int numGenerationRows = generation.getNumRowsInGeneration();
	int numGenerationCols = generation.getNumColumnsInGeneration();

	bool inTopLeftCorner = false;
	bool inTopRightCorner = false;
	bool inBottomLeftCorner = false;
	bool inBottomRightCorner = false;
	bool inFirstRow = false;
	bool inLastRow = false;
	bool inFirstColumn = false;
	bool inLastColumn = false;

	if(rowIndex == 0 && colIndex == 0)
	{
		inTopLeftCorner = true;
	}

	if((rowIndex == 0) && (colIndex == numGenerationCols - 1))
	{
		inTopRightCorner = true;
	}

	if((rowIndex == numGenerationRows - 1) && (colIndex == 0))
	{
		inBottomLeftCorner = true;
	}

	if((rowIndex == numGenerationRows - 1) && (colIndex == numGenerationCols - 1))
	{
		inBottomRightCorner = true;
	}

	if(rowIndex == 0 && colIndex != 0)
	{
		inFirstRow = true;
	}

	if(rowIndex == numGenerationRows - 1 && colIndex != 0)
	{
		inLastRow = true;
	}

	if(rowIndex != 0 && colIndex == 0)
	{
		inFirstColumn = true;
	}

	if(rowIndex != 0 && colIndex == numGenerationCols - 1)
	{
		inLastColumn = true;
	}

	if(inTopLeftCorner)
	{
		char neighbor1 = generation.getCell(rowIndex, colIndex+1);
		arrayOfNeighbors[0] = neighbor1;

		char neighbor2 = generation.getCell(rowIndex+1, colIndex+1);
		arrayOfNeighbors[1] = neighbor2;

		char neighbor3 = generation.getCell(rowIndex+1, colIndex);
		arrayOfNeighbors[2] = neighbor3;
	}

	else if(inTopRightCorner)
	{
		char neighbor1 = generation.getCell(rowIndex, colIndex-1);
		arrayOfNeighbors[0] = neighbor1;

		char neighbor2 = generation.getCell(rowIndex+1, colIndex-1);
		arrayOfNeighbors[1] = neighbor2;

		char neighbor3 = generation.getCell(rowIndex+1, colIndex);
		arrayOfNeighbors[2] = neighbor3;
	}

	else if(inBottomLeftCorner)
	{
		char neighbor1 = generation.getCell(rowIndex-1, colIndex);
		arrayOfNeighbors[0] = neighbor1;

		char neighbor2 = generation.getCell(rowIndex+1, colIndex+1);
		arrayOfNeighbors[1] = neighbor2;

		char neighbor3 = generation.getCell(rowIndex, colIndex+1);
		arrayOfNeighbors[2] = neighbor3;
	}

	else if(inBottomRightCorner)
	{
		char neighbor1 = generation.getCell(rowIndex, colIndex-1);
		arrayOfNeighbors[0] = neighbor1;

		char neighbor2 = generation.getCell(rowIndex-1, colIndex-1);
		arrayOfNeighbors[1] = neighbor2;

		char neighbor3 = generation.getCell(rowIndex-1, colIndex);
		arrayOfNeighbors[2] = neighbor3;
	}

	else if((rowIndex == 0) && (colIndex != 0))
	{
		char neighbor1 = generation.getCell(rowIndex, colIndex - 1);
		arrayOfNeighbors[0] = neighbor1;

		char neighbor2 = generation.getCell(rowIndex, colIndex + 1);
		arrayOfNeighbors[1] = neighbor1;

		char neighbor3 = generation.getCell(rowIndex + 1, colIndex - 1);
		arrayOfNeighbors[2] = neighbor3;

		char neighbor4 = generation.getCell(rowIndex + 1, colIndex + 1);
		arrayOfNeighbors[3] = neighbor4;

		char neighbor5 = generation.getCell(rowIndex + 1, colIndex);
		arrayOfNeighbors[4] = neighbor5;
	}

}
