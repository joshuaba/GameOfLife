#include <iostream>
#include <string>

#include "GameOfLife.h"

using namespace std;

int main(int argc, char** argv)
{

	GameOfLife simulation1;
	cout << "Would you like to provide a map file to simulate the program?" << endl;
		char userAnswer;
		cin >> userAnswer;

		if(userAnswer == 'Y' || userAnswer == 'y')
		{

			simulation1 = GameOfLife('Y');
		}

		else
		{
			cout << "What are the dimensions of the \"world\"? Type in two integers, the first representing the number of rows and the second representing the number of columns" << endl;
			int numRows, numColumns;

			cin >> numRows >> numColumns;

			cout << "What mode would you like to play the program in? Type \'C\' for classic, \'M\' for mirror, or \'D\' for doughnut." << endl;
			char mode;
			cin >> mode;

			cout << "Type in the population density: " << endl;
			float popDensity;
			cin >> popDensity;

			simulation1 = GameOfLife(numRows, numColumns, popDensity, mode);

			//cin.get(); //clear the buffer in order to print out the first worldArray in the while loop

		}

		while(simulation1.getWereNeighborsFound() == true || simulation1.getWasWorldChanged() == true)
		{
			simulation1.toggleWorlds();

			for (int curRow = 0; curRow < (simulation1.getWorld0()).getNumOfRows(); ++curRow)
			{
				for (int curCol = 0; curCol < (simulation1.getWorld0()).getNumOfColumns(); ++curCol)
				{
					int totalPopulatedNeighbors = (simulation1.getSourceWorld()).getNumberOfPopulatedNeighbors(curRow, curCol);

					if(totalPopulatedNeighbors > 0)
					{
						simulation1.setWereNeighborsFound(true);
					}

					if(totalPopulatedNeighbors <= 1)
					{
						//cell dies
						(simulation1.getTargetWorld()).setCellValue(curRow, curCol, '-');
					}

					if(totalPopulatedNeighbors == 2)
					{
						(simulation1.getTargetWorld()).setCellValue(curRow, curCol, (simulation1.getSourceWorld()).getCellValue(curRow, curCol));
					}

					if(totalPopulatedNeighbors == 3)
					{
						(simulation1.getTargetWorld()).setCellValue(curRow, curCol, 'X');
					}

					if(totalPopulatedNeighbors >= 4)
					{
						(simulation1.getTargetWorld()).setCellValue(curRow, curCol, '-');
					}

					if((simulation1.getSourceWorld()).getCellValue(curRow, curCol) != (simulation1.getTargetWorld()).getCellValue(curRow, curCol))
					{
						simulation1.setWasWorldChanged(true);
					}
				}
			}

			cout << "Hit \'Enter\' to display the world!" << endl;


			if(cin.get() == '\n')
			{
				(simulation1.getSourceWorld()).printWorldArrayToConsole();
			}

			cout << endl;

			(simulation1.getSourceWorld()).cloneWorldToCurrent(simulation1.getTargetWorld());
		}
}

