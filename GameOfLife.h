#include <iostream>
#include <string>

#include "World.h"

using namespace std;

class GameOfLife
{
	public:

		GameOfLife(); //default constructor
		GameOfLife(int numRows, int numColumns, char theMode); //creates an instance of GameOfLife, creating the worlds based on input from a file
		GameOfLife(char fromFile);
		GameOfLife(int numRows, int numColumns, float popDensity, char theMode);

		void toggleWorlds(); //switch between worlds, setting world1 and world 0 as the source world and target world
		void populateFirstWorldsFromFile();
		void randomizeFirstWorld(int numRows, int numColumns, float popDensity, char theMode);

		World getWorld0();
		World getWorld1();
		World getSourceWorld();
		World getTargetWorld();

		bool getWasWorldChanged();
		bool getWereNeighborsFound();
		void setWasWorldChanged(bool changed);
		void setWereNeighborsFound(bool found);

	private:

		World world0;
		World world1;
		World sourceWorld; //the world to be created looks at this world to determine whether its members will be populated or empty
		World targetWorld; //world to be created according to the rules of the Game of Life

		int currentWorld;
		bool wasWorldChanged;
		bool wereNeighborsFound;



};

