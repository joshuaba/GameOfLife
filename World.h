#include <iostream>
#include <string>

using namespace std;


class World
{
	public:
		World(); //default constructor, creates an empty world

		World(int numRows, int numColumns, char mode); //creates an instance of the World class -- populates a numRows by numColumns world and sets the mode

		void cloneWorldToCurrent(World thisWorld); //clones the recently created world to the current world

		void setCellValue(int row, int col, char value); //set the value of the worldArray at location [row][col] to value

		void printWorldArrayToConsole(); //print out the world array to the console

		char getCellValue(int row, int col); //return the character in worldArray at [row][col]

		char getNeighborCellValue(int row, int col, char subjectCellValue); //gets the value of one of neighbors of the cell at [row][col]

		int getNumberOfPopulatedNeighbors(int row, int col); //returns the number of populated neighbors the cell at [row][col] has

		int getNumOfRows();

		int getNumOfColumns();




	private:
		int numOfRows;
		int numOfCols;
		char mode;
		char** worldArray;

};
