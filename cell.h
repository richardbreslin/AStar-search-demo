#pragma once
#include <vector>

using namespace std;
class cell
{
public:
	void setCellType(int acellType);
	int getCellType();

	cell();
	bool bObstacle = false; // is the cell a wall?
	bool bVisited = false;	// Have we searched this cell before?
	float fGlobalGoal;		// Distance to goal so far
	float fLocalGoal;		// Distance to goal if we took the alternative route
	int x;					// cell position in 2D space
	int y;
	vector<cell *> vecNeighbours; // Connections to neighbours
	cell *parent;				  // cell connecting to this cell that offers shortest parent
	cell *cellStart = nullptr;
	cell *cellEnd = nullptr;

private:
	int cellType;
};
