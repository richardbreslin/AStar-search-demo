#pragma once
//Richie Breslin Rodney Breslin
// CSC 2110
//Final Project using A* Algorithm
class position
{
public:
	void setColumn(int acolumn);
	void setRow(int arow);
	int getColumn();
	int getRow();
	position();
	position(int arow, int acolumn);

private:
	int column;
	int row;
};
