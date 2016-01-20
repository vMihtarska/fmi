#pragma once
#include <iostream>
struct Position
{
	int row, col;
	int neig;
	Position()
	{
		row = 0;
		col = 0;
		neig = 0;
	}
	Position(int Row, int Col,int neig=0)
	{
		row = Row;
		col = Col;
		neig = neig;
	}
	Position(const Position& o)
	{
		this->row = o.row;
		this->col = o.col;
		this->neig = o.neig;
	}
	void set(int Row, int Col,int neig=0)
	{
		row = Row;
		col = Col;
		neig = neig;
	}
	void setneig(int neig)
	{
		this->neig = neig;
	}
	bool operator==(Position & r) const
	{
		if (this->row == r.row&&this->col == r.col)
			return true;
		else return false;
	}
	void print() const
	{
		std::cout << "(" << row << "," << col << ")";
	}
};
