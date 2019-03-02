/*
Generations.h
 *
 *  Created on: Feb 28, 2019
 *      Author: Joshua (Non-Admin)
 */
#include <iostream>
#include <string>

typedef char* myPtr;

class Generations
{
	public:
		Generations(); //default constructor, initalizes the world to a 1 x 1 grid with a cell populated
		Generations(int numRows, int numColumns); //initalizes the world as a numRows x numColumns environment with a population density of popDensity

		myPtr getGeneration();
		//Post-condition: returns the current generation grid. It returns myPtr *a defined below

		int getNumRowsInGeneration();
		int getNumColumnsInGeneration();

		void populateGeneration(int rowIndex, int colIndex, char charToAdd); //randomly populates the world to which myPtr *a belongs



	private:

		int numRows, numColumns; //determine the dimensions of the "world" defined by myPtr *a

		myPtr *a;


};

