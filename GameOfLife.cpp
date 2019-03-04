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

	//myPtr currentGeneration = getGeneration();
}

myPtr GameOfLife::neighborArray(Generations generation, int rowIndex, int colIndex)
{
	myPtr arrayOfNeighbors;
	arrayOfNeighbors = new char[10];

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

	//determine what cell we are in: corner cell, cell in the first or last row/column, or cell in the interior of the grid

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

	else if(inFirstRow)
	{
		char neighbor1 = generation.getCell(rowIndex, colIndex - 1);
		arrayOfNeighbors[0] = neighbor1;

		char neighbor2 = generation.getCell(rowIndex, colIndex + 1);
		arrayOfNeighbors[1] = neighbor2;

		char neighbor3 = generation.getCell(rowIndex + 1, colIndex - 1);
		arrayOfNeighbors[2] = neighbor3;

		char neighbor4 = generation.getCell(rowIndex + 1, colIndex + 1);
		arrayOfNeighbors[3] = neighbor4;

		char neighbor5 = generation.getCell(rowIndex + 1, colIndex);
		arrayOfNeighbors[4] = neighbor5;
	}

	else if(inLastRow)
	{
		char neighbor1 = generation.getCell(rowIndex, colIndex - 1);
		arrayOfNeighbors[0] = neighbor1;

		char neighbor2 = generation.getCell(rowIndex, colIndex + 1);
		arrayOfNeighbors[1] = neighbor2;

		char neighbor3 = generation.getCell(rowIndex + 1, colIndex - 1);
		arrayOfNeighbors[2] = neighbor3;

		char neighbor4 = generation.getCell(rowIndex + 1, colIndex + 1);
		arrayOfNeighbors[3] = neighbor4;

		char neighbor5 = generation.getCell(rowIndex + 1, colIndex);
		arrayOfNeighbors[4] = neighbor5;
	}

	else if(inFirstColumn)
	{
		char neighbor1 = generation.getCell(rowIndex - 1, colIndex);
		arrayOfNeighbors[0] = neighbor1;

		char neighbor2 = generation.getCell(rowIndex - 1, colIndex + 1);
		arrayOfNeighbors[1] = neighbor2;

		char neighbor3 = generation.getCell(rowIndex, colIndex + 1);
		arrayOfNeighbors[2] = neighbor3;

		char neighbor4 = generation.getCell(rowIndex + 1, colIndex + 1);
		arrayOfNeighbors[3] = neighbor4;

		char neighbor5 = generation.getCell(rowIndex + 1, colIndex);
		arrayOfNeighbors[4] = neighbor5;
	}

	else if(inLastColumn)
	{
		char neighbor1 = generation.getCell(rowIndex - 1, colIndex);
		arrayOfNeighbors[0] = neighbor1;

		char neighbor2 = generation.getCell(rowIndex - 1, colIndex - 1);
		arrayOfNeighbors[1] = neighbor2;

		char neighbor3 = generation.getCell(rowIndex, colIndex - 1);
		arrayOfNeighbors[2] = neighbor3;

		char neighbor4 = generation.getCell(rowIndex + 1, colIndex - 1);
		arrayOfNeighbors[3] = neighbor4;

		char neighbor5 = generation.getCell(rowIndex + 1, colIndex);
		arrayOfNeighbors[4] = neighbor5;
	}

	else
	{
		char neighbor1 = generation.getCell(rowIndex - 1, colIndex); //cell directly above the current cell
		arrayOfNeighbors[0] = neighbor1;

		char neighbor2 = generation.getCell(rowIndex - 1, colIndex + 1); //cell to the top-right of the current cell
		arrayOfNeighbors[1] = neighbor2;

		char neighbor3 = generation.getCell(rowIndex, colIndex + 1); //cell to the right of the current cell
		arrayOfNeighbors[2] = neighbor3;

		char neighbor4 = generation.getCell(rowIndex + 1, colIndex + 1); //cell to the bottom-right of the current cell
		arrayOfNeighbors[3] = neighbor4;

		char neighbor5 = generation.getCell(rowIndex, colIndex - 1); //cell directly below the current cell
		arrayOfNeighbors[4] = neighbor5;

		char neighbor6 = generation.getCell(rowIndex + 1, colIndex - 1); //cell to the bottom-left of the current cell
		arrayOfNeighbors[5] = neighbor6;

		char neighbor7 = generation.getCell(rowIndex, colIndex - 1); //cell to the left of the current cell
		arrayOfNeighbors[6] = neighbor7;

		char neighbor8 = generation.getCell(rowIndex - 1, colIndex - 1); //cell to the top-left of the current cell
		arrayOfNeighbors[7] = neighbor8;

	}

	return arrayOfNeighbors;
}

void GameOfLife::populateNextGeneration(Generations currentGeneration, int numRows, int numColumns)
{
	arrayOfNeighbors = new char[10];
	Gen1World = Generations(numRows, numColumns);

	for (int i = 0; i < numRows; ++i)
	{
		for (int j = 0; j < numColumns; ++j)
		{
			int countOfNeighbors = 0;
			arrayOfNeighbors = neighborArray(currentGeneration, i, j);

			for (int k = 0; i < 10; ++k)
			{
				if(arrayOfNeighbors[k] == 'X' || arrayOfNeighbors[k] == 'x')
				{
					countOfNeighbors++;
				}
			}

			if(countOfNeighbors <= 1)
			{
				Gen1World.populateGeneration(i,j,'-');
			}

			else if(countOfNeighbors == 2)
			{
				if(currentGeneration.getCell(i,j) == 'X' || currentGeneration.getCell(i,j) == 'x')
				{
					Gen1World.populateGeneration(i,j,'X');
				}
				else
				{
					Gen1World.populateGeneration(i,j,'-');
				}
			}

			else if(countOfNeighbors == 3)
			{
				Gen1World.populateGeneration(i,j,'X');
			}

			else
			{
				Gen1World.populateGeneration(i,j,'-');
			}
		}
	}

	switchGenerations(Gen0World, Gen1World);
}

myPtr neighborArrayDoughnut(Generations generation, int rowIndex, int colIndex)
{

}


void GameOfLife::switchGenerations(Generations generation1, Generations generation2)
{
	generation1 = generation2;
}


