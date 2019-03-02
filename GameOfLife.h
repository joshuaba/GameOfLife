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

		void populateNextGeneration(myPtr a, int numOfRows, int numOfColumns);
		//Pre-condition: Generation 0 has been populated
		//Post-condition: Generation 1 will be populated according to the rules

		//void findNeighbors(myPtr a);

		//void populateArrayOfNeighbors(char character);

	private:
		Generations Gen0World;
		Generations Gen1World;

		myPtr neighborArray(Generations generation, int rowIndex, int colIndex);
		//Pre-condition: a virtual "world" exists
		//Post-condition: determine the neighboring cells of the location passed into the function (location being described by rowIndex and colIndex) and populate a char neighborArray with the neighbors

};

