#include <iostream>
#include <string>
#include <cstdlib>
#include "Generations.h"

using namespace std;

typedef char* myPtr;

class GameOfLife
{
	public:
		void populateGenZeroFromFile();
		//Pre-condition: the user has either passed in a map file or has chosen to randomly create a "world"
		//Post-condition: the first bacterial generation is populated according to the map file or randomly

		void randomizeWorld(int numRows, int numColumns, float popDensity);
		//Pre-condition: the user has requested the "world" to be randomized rather than providing a map file
		//Post-condition: a random world (grid) has been created with the dimensions typed in by the user and populated according to the population density requested by the user

		void populateNextGeneration(Generations currentGeneration, int numOfRows, int numOfColumns);
		//Pre-condition: Generation 0 has been populated
		//Post-condition: Generation 1 will be populated according to the rules

		void switchGenerations(Generations generation1, Generations generation2);

	private:
		Generations Gen0World;
		Generations Gen1World;
		myPtr arrayOfNeighbors;
		//string neighbors;

		myPtr neighborArray(Generations generation, int rowIndex, int colIndex);
		//Pre-condition: a virtual "world" exists
		//Post-condition: determine the neighboring cells of the location passed into the function (location being described by rowIndex and colIndex) and populate a char neighborArray with the neighbors

		myPtr neighborArrayDoughnut(Generations generation, int rowIndex, int colIndex);
		//Pre-condition: a virutal "world" exists
		//Post-condition: determine the neighboring cells of the location passed into the function (location being described by rowIndex and colIndex) and populate a char neighborArray
		//same functionality as neighborArray(Generation, int, int) method, except for Doughnut mode

};

