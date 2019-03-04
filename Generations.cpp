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

	a = new char* [numRows];

	*a[0] = '-';
}

Generations::Generations(int numOfRows, int numOfColumns)
{
	numRows = numOfRows;
	numColumns = numOfColumns;

	//float densityOfPopulation = popDensity;

	a = new char*[numRows];

	for (int i = 0; i < numRows; ++i)
	{
		a[i] = new char[numColumns];
	}
}

Generations::~Generations()
{
	for (int i = 0; i < numRows; ++i)
	{
		delete[] a[i];
	}

	delete[] a;
}

void Generations::populateGeneration(int rowIndex, int colIndex, char charToAdd)
{
	a[rowIndex][colIndex] = charToAdd;
}

char** Generations::getGeneration()
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




