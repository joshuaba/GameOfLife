#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

class GameOfLife
{
	public:
		void populateGenZeroFromFile();
		//Pre-condition: the user has either passed in a map file or has chosen to randomly create a "world"
		//Post-condition: the first bacterial generation is populated according to the map file or randomly

		void randomizeWorld(int numRows, int numColumns);
};
