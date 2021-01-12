#include "cell.h"
#include <vector>
//Richie Breslin Rodney Breslin
// CSC 2110
//Final Project using A* Algorithm
void cell::setCellType(int acellType)
{
	cellType = acellType;
}
int cell::getCellType()
{
	return cellType;
}
cell::cell()
{
	cellType = 0;
}