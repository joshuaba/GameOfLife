#include "World.h"

#include <iostream>
#include <string>


using namespace std;

World::World()
{
	numOfRows = 2;
	numOfCols = 2;
	mode = 'M';
	worldArray = new char* [numOfRows];

	for(int i = 0; i < numOfRows; ++i)
	{
		worldArray[i] = new char [numOfCols];
	}
}

World::World(int numRows, int numColumns, char theMode)
{
	numOfRows = numRows;
	numOfCols = numColumns;
	mode = theMode;

	worldArray = new char* [numOfRows];

	for(int i = 0; i < numOfRows; ++i)
	{
		worldArray[i] = new char [numOfCols];
	}
}

void World::cloneWorldToCurrent(World thisWorld)
{
	worldArray = thisWorld.worldArray;
}

void World::setCellValue(int row, int col, char value)
{
	worldArray[row][col] = value;
}

void World::printWorldArrayToConsole()
{
	for (int i = 0; i < numOfRows; ++i)
	{
		for (int j = 0; j < numOfCols; ++j)
		{
			cout << worldArray[i][j];
		}
		cout << endl;
	}
}

char World::getCellValue(int row, int col)
{
	return worldArray[row][col];
}

char World::getNeighborCellValue(int row, int col, char subjectCellValue) //subject cell being the cell whose neighbors the method will find
{
	//if the row or col is out of bounds of the gridArray, then

	if((row < 0) || (row >= numOfRows) || (col == 0) || (col >= numOfCols - 1))
	{
		if(mode == 'C')
		{
			return 'E';
		}

		else if(mode == 'M')
		{
			return subjectCellValue;
		}

		else //then doughnut mode is the mode
		{
			int effectiveRow, effectiveCol;

			if(row < 0)
			{
				effectiveRow = numOfRows - 1;
			}

			if(row >= numOfRows - 1)
			{
				effectiveRow = 0;
			}

			if(col < 0)
			{
				effectiveCol = numOfCols - 1;
			}

			if (col >= numOfCols - 1)
			{
				effectiveCol = 0;
			}

			return worldArray[effectiveRow][effectiveCol];
		}
	}

	else //the requested neighbor is in bounds of the grid
	{
		return worldArray[row][col];
	}
}

int World::getNumberOfPopulatedNeighbors(int row, int col)
{
	char subjectCellValue = getCellValue(row, col);

	int populatedNeighborCells = 0;

	if(getNeighborCellValue(row - 1, col - 1, subjectCellValue) == 'X')
	{
		populatedNeighborCells++;
	}

	if(getNeighborCellValue(row-1, col, subjectCellValue) == 'X')
	{
		populatedNeighborCells++;
	}

	if(getNeighborCellValue(row-1, col+1, subjectCellValue) == 'X')
	{
		populatedNeighborCells++;
	}

	if(getNeighborCellValue(row, col+1, subjectCellValue) == 'X')
	{
		populatedNeighborCells++;
	}

	if(getNeighborCellValue(row+1, col+1, subjectCellValue) == 'X')
	{
		populatedNeighborCells++;
	}

	if(getNeighborCellValue(row+1, col, subjectCellValue) == 'X')
	{
		populatedNeighborCells++;
	}

	if(getNeighborCellValue(row+1, col-1, subjectCellValue) == 'X')
	{
		populatedNeighborCells++;
	}

	if(getNeighborCellValue(row, col - 1, subjectCellValue) == 'X')
	{
		populatedNeighborCells++;
	}

	return populatedNeighborCells;
}

int World::getNumOfRows()
{
	return numOfRows;
}

int World::getNumOfColumns()
{
	return numOfCols;
}
