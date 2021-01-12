
#pragma once
#include <vector>
#include "position.h"
#include "cell.h"
//Richie Breslin Rodney Breslin
// CSC 2110
//Final Project using A* Algorithm
using namespace std;
class pathfinder
{
public:
	void search();
	pathfinder(cell *pmap, int initialColumn, int initialRow);
	void display();

private:
	cell *map;
	position currentPosition;
	// Set width and height to 2d array size
	const int MAP_WIDTH = 5;
	const int MAP_HEIGHT = 6;
	// Initial Start Point
	int START_X;
	int START_Y;
	//Goal Point
	int END_X;
	int END_Y;
	cell *_MAP = nullptr;
	cell *cellStart = nullptr;
	cell *cellEnd = nullptr;
};
