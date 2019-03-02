/*
   Generations.cpp
   Created on: Feb 28, 2019
   Author: Joshua (Non-Admin)
 */

#include <iostream>
#include <string>
#include "Generations.h"

using namespace std;

Generations::Generations()
{
	numRows = 1;
	numColumns = 1;

	a = new char[1];

	for (int i = 0; i < numRows; ++i)
	{
		a = new char[numColumns];
	}

	for (int i = 0; i < numRows; ++i)
	{
		for (int j = 0; j < numColumns; ++j)
		{
			a[i][j] = '-';
		}
	}
}

Generations::Generations(int numOfRows, int numOfColumns)
{
	numRows = numOfRows;
	numColumns = numOfColumns;
	float densityOfPopulation = popDensity;

	a = new char[numRows];

	for (int i = 0; i < numRows; ++i)
	{
		a = new char[numColumns];
	}
}

void Generations::populateGeneration(int rowIndex, int colIndex, char charToAdd)
{
	a[rowIndex][colIndex] = charToAdd;
}

myPtr Generations::getGeneration()
{
	return a;
}

int Generations::getNumRowsInGeneration()
{
	return numRows;
}

int Generations::getNumColumnsInGeneration()
{
	return numColumns;
}

char Generations::getCell(int rowIndex, int colIndex)
{
	return a[rowIndex][colIndex];
}




