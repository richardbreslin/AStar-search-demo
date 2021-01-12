#include "position.h"
//Richie Breslin Rodney Breslin
// CSC 2110
//Final Project using A* Algorithm
//Mutator Methods
void position::setColumn(int acolumn)
{
	column = acolumn;
}
void position::setRow(int arow)
{
	row = arow;
}
//Accessor Methods
int position::getColumn()
{
	return column;
}
int position::getRow()
{
	return row;
}
//Default Constructor
position::position()
{
	row = 0;
	column = 0;
}
//Constructor with parameters
position::position(int arow, int acolumn)
{
	row = arow;
	column = acolumn;
}