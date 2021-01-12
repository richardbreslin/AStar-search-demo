#include "pathfinder.h"
#include <vector>
#include <iostream>
#include <list>
#include <limits>
#include "math.h"
//Richie Breslin Rodney Breslin
// CSC 2110
//Final Project using A* Algorithm
using namespace std;

pathfinder::pathfinder(cell *pmap, int initialColumn, int initialRow)
{
	_MAP = new cell[MAP_WIDTH * MAP_HEIGHT];
	//Set initial Position
	currentPosition.setColumn(initialColumn);
	currentPosition.setRow(initialRow);
	map = pmap;
	START_X = currentPosition.getColumn();
	START_Y = currentPosition.getRow();
	for (int i = 0; i < MAP_WIDTH; i++)
	{
		for (int j = 0; j < MAP_HEIGHT; j++)
		{
			_MAP[j * MAP_WIDTH + i].setCellType(map[j * MAP_WIDTH + i].getCellType());
		}
	}
	for (int x = 0; x < MAP_WIDTH; x++)
	{
		for (int y = 0; y < MAP_HEIGHT; y++)
		{
			//giving each cell its own coordinate
			_MAP[y * MAP_WIDTH + x].x = x;
			_MAP[y * MAP_WIDTH + x].y = y;
			_MAP[y * MAP_WIDTH + x].bObstacle = false;
			_MAP[y * MAP_WIDTH + x].parent = nullptr;
			_MAP[y * MAP_WIDTH + x].bVisited = false;

			if (_MAP[y * MAP_WIDTH + x].getCellType() == 1)
			{
				_MAP[y * MAP_WIDTH + x].bObstacle = true;
			}
		}
	}
	//linking the cells in a grid formation
	for (int x = 0; x < MAP_WIDTH; x++)
	{
		for (int y = 0; y < MAP_HEIGHT; y++)
		{
			if (y > 0)
				_MAP[y * MAP_WIDTH + x].vecNeighbours.push_back(&_MAP[(y - 1) * MAP_WIDTH + (x + 0)]);
			if (y < MAP_HEIGHT - 1)
				_MAP[y * MAP_WIDTH + x].vecNeighbours.push_back(&_MAP[(y + 1) * MAP_WIDTH + (x + 0)]);
			if (x > 0)
				_MAP[y * MAP_WIDTH + x].vecNeighbours.push_back(&_MAP[(y + 0) * MAP_WIDTH + (x - 1)]);
			if (x < MAP_WIDTH - 1)
				_MAP[y * MAP_WIDTH + x].vecNeighbours.push_back(&_MAP[(y + 0) * MAP_WIDTH + (x + 1)]);
		}
	}
	for (int i = 0; i < MAP_WIDTH; i++)
	{
		for (int j = 0; j < MAP_HEIGHT; j++)
		{
			if (_MAP[j * MAP_WIDTH + i].getCellType() == 2)
			{
				END_X = _MAP[j * MAP_WIDTH + i].x;
				END_Y = _MAP[j * MAP_WIDTH + i].y;
			}
		}
	}
	cellEnd = &_MAP[END_Y * MAP_WIDTH + END_X];
	cellStart = &_MAP[START_Y * MAP_WIDTH + START_X];
}
void pathfinder::display()
{
	if (cellEnd != nullptr)
	{
		cell *p = cellEnd;
		while (p->parent != nullptr)
		{
			cout << "(" << p->x << ", " << p->y << ")"
				 << "<-";
			// Set next node to this node's parent
			p = p->parent;
		}
		cout << "(" << START_X << ", " << START_Y << ")" << endl;
	}
}
void pathfinder::search()
{

	// Set Defaults
	//Each cell has not been visited and has no parents.
	for (int x = 0; x < MAP_WIDTH; x++)
		for (int y = 0; y < MAP_HEIGHT; y++)
		{
			_MAP[y * MAP_WIDTH + x].bVisited = false;
			_MAP[y * MAP_WIDTH + x].fGlobalGoal = INFINITY;
			_MAP[y * MAP_WIDTH + x].fLocalGoal = INFINITY;
			_MAP[y * MAP_WIDTH + x].parent = nullptr;
		}

	//Lamda func. Returns the distance between two cells
	auto distance = [](cell *a, cell *b) {
		return sqrtf((a->x - b->x) * (a->x - b->x) + (a->y - b->y) * (a->y - b->y));
	};

	auto heuristic = [distance](cell *a, cell *b) {
		return distance(a, b);
	};

	//Initialize starting conditions
	cell *cellCurrent = cellStart;
	cellStart->fLocalGoal = 0.0f;
	cellStart->fGlobalGoal = heuristic(cellStart, cellEnd);
	list<cell *> listNotTestedCells;
	listNotTestedCells.push_back(cellStart);

	while (!listNotTestedCells.empty() && cellCurrent != cellEnd)
	{

		//Sort Untested nodes by global
		listNotTestedCells.sort([](const cell *lhs, const cell *rhs) { return lhs->fGlobalGoal < rhs->fGlobalGoal; });

		//delete nodes that have been visted.
		while (!listNotTestedCells.empty() && listNotTestedCells.front()->bVisited)
		{
			listNotTestedCells.pop_front();
		}

		//Abort if no valid nodes left to test
		if (listNotTestedCells.empty())
		{
			break;
		}

		//make sure we only visit a node once.
		cellCurrent = listNotTestedCells.front();
		cellCurrent->bVisited = true;

		for (auto cellNeighbour : cellCurrent->vecNeighbours)
		{
			// ... and only if the neighbour is not visited and is
			// not an obstacle, add it to NotTested List
			if (!cellNeighbour->bVisited && cellNeighbour->bObstacle == 0)
				listNotTestedCells.push_back(cellNeighbour);

			// Calculate the neighbours potential lowest parent distance
			float fPossiblyLowerGoal = cellCurrent->fLocalGoal + distance(cellCurrent, cellNeighbour);

			if (fPossiblyLowerGoal < cellNeighbour->fLocalGoal)
			{
				cellNeighbour->parent = cellCurrent;
				cellNeighbour->fLocalGoal = fPossiblyLowerGoal;

				cellNeighbour->fGlobalGoal = cellNeighbour->fLocalGoal + heuristic(cellNeighbour, cellEnd);
			}
		}
	}

	//shortest path is linked via the parent pointer in the cell type.
	//so as long as the end does not equal a nullptr we can follow the
	//parent tree up the shortest path and print outt along the way.
	// if (cellEnd != nullptr)
	// {
	// 	cell *p = cellEnd;
	// 	while (p->parent != nullptr)
	// 	{
	// 		cout << "(" << p->x << ", " << p->y << ")"
	// 			 << "<-";
	// 		// Set next node to this node's parent
	// 		p = p->parent;
	// 	}
	// 	cout << "(" << START_X << ", " << START_Y << ")" << endl;
	// }
}
