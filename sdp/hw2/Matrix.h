#pragma once
#include <iostream>
#include "Position.h"
#include "Queue.h"
#include "List.h"
class Matrix
{
private:
	int N, M;
	char** arr;
	bool ** boolarr;
	Position start;

public:
	Matrix() :N(0), M(0), arr(nullptr), boolarr(nullptr), start() {};
	void ReadMatrix()
	{
		do
		{
			std::cout << "Enter a size of the matrix:" << std::endl;
			std::cin >> N >> M;

		} while (N < 0 || M < 0);
		arr = new char*[N];
		boolarr = new bool*[N];
		for (int i = 0; i < N; i++)
		{
			arr[i] = new char[M];
			boolarr[i] = new bool[M];
		}
		std::cout << "Enter the matrix:" << std::endl;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
			{
				std::cin >> arr[i][j];
				if (arr[i][j] == '.')
					boolarr[i][j] = 1;
				else boolarr[i][j] = 0;
			}
		int x, y;
		std::cout << "Enter a start position:" << std::endl;
		std::cin >> x >> y;
		start.set(x, y);
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
			{
				Position temp(i, j);
				if (boolarr[i][j] == 1 && !(temp == this->start))
				{
					temp.print();
				}
			}
		std::cout << std::endl;
	}
	int getCount(bool** arr)
	{
		int count = 0;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
			{

				if (boolarr[i][j] == 1)
					count++;
			}
		return count;
	}
	bool isFound(List<Position> path, Position pos)
	{
		for (Iterator<Position> iterator = path.GetIterator();
		!iterator.EndReached();
			iterator.MoveNext())
		{
			if (iterator.GetCurrent() == pos)
				return true;
		}
		return false;
	}
	bool canPass(Position pos)
	{
		if (pos.row < N && pos.col < M && pos.row >= 0 && pos.col >= 0 && boolarr[pos.row][pos.col])
		{
			return true;
		}
		else return false;
	}
	bool IsN(Position& o, Position & t) const
	{
		int dr[] = { 0,-1,0,1 };
		int dc[] = { -1,0,1,0 };
		for (int i = 0; i < 4; ++i)
		{
			Position next(o.row + dr[i], o.col + dc[i]);
			if (next == t)
			{
				return true;
			}

		}
		return false;
	}
	int NumberOfNeig(Position& pos)
	{
		int dr[] = { 0,-1,0,1 };
		int dc[] = { -1,0,1,0 };
		int count = 0;
		for (int i = 0; i < 4; ++i)
		{
			Position next(pos.row + dr[i], pos.col + dc[i]);
			if (canPass(next))
			{
				count++;
			}

		}
		return count;
	}
	
	void BFS(Position a)
	{
		Queue<Position> pos;
		List<Position> path;
		List<List<Position>> p;
		Position curr;
		int size = getCount(this->boolarr);
		pos.push(start);
		path.AddTail(start);
		List<List<Position>> sorted;
		this->boolarr[start.row][start.col] = 0;
		int dr[] = { 0,-1,0,1 };
		int dc[] = { -1,0,1,0 };
		int count = 0;
		bool firstTime = true;
		bool hasMached = false;
		while (!pos.isEmpty())
		{
			curr.set(pos.top().row, pos.top().col);
			pos.pop();
			for (int i = 0; i < 4; ++i)
			{
				Position next(curr.row + dr[i], curr.col + dc[i]);
				next.neig = NumberOfNeig(next);
				if (canPass(next))
				{
					
					path.AddTail(next);
					if (firstTime)
					{
						p.AddTail(path);
					}
					if (p.GetTail().GetSize() > size)
					{
						std::cout << size;
						return;
					}

					int founds = 0;
					for (Iterator<List<Position>> iterator = p.GetIterator();
					!iterator.EndReached();
						iterator.MoveNext())
					{
						int Num = NumberOfNeig(iterator.GetCurrent().GetTail());
						if (iterator.GetCurrent().GetTail() == curr&& !isFound(iterator.GetCurrent(), next) && !(iterator.GetCurrent().GetTail() == a))
						{

							if (!firstTime)
								founds++;
							if (iterator.GetCurrent().GetTail().neig > 1)
							{
								iterator.GetCurrent().GetTail().neig = iterator.GetCurrent().GetTail().neig - 1;
								p.AddHead(iterator.GetCurrent());
								iterator.GetCurrent().AddTail(next);
							}
							else
							{
								iterator.GetCurrent().AddTail(next);
							}
						}

					}

					if (next == a)
					{
						path.RemoveTail();
						continue;
					}
					path.RemoveTail();
					if (firstTime)
						founds++;
					if (!(next == a) && !(pos == next) && founds)
						pos.push(next);


				}

			}
			
			firstTime = false;

			}


		
		std::cout << std::endl;
		
		for (Iterator<List<Position>> iterator = p.GetIterator();
		!iterator.EndReached();
			iterator.MoveNext())
		{

			for (Iterator<List<Position>> iterator = p.GetIterator();
			!iterator.EndReached();
				iterator.MoveNext())
			{
				if (iterator.GetCurrent().GetTail() == a)
				{

					hasMached = false;
					if (sorted.isEmpty())
					{
						sorted.AddTail(iterator.GetCurrent());
						
					}
					else
					{
						for (Iterator<List<Position>> iterator2 = sorted.GetIterator();
						!iterator2.EndReached();
							iterator2.MoveNext())
						{

							if (iterator2.GetCurrent() == iterator.GetCurrent())
							{
								hasMached = true;
								break;
							}

						}
						if (hasMached == false)
						{
							if(iterator.GetCurrent().GetSize()<sorted.GetHead().GetSize())
							sorted.AddHead(iterator.GetCurrent());
							else if(iterator.GetCurrent().GetSize()>sorted.GetTail().GetSize())
								sorted.AddTail(iterator.GetCurrent());
							else 
							{
								for (Iterator<List<Position>> iterator3 = sorted.GetIterator();
								!iterator3.EndReached();
									iterator3.MoveNext())
								{
									if (iterator3.GetCurrent().GetSize() >= iterator.GetCurrent().GetSize())
									{
										sorted.InsertAfter(iterator3.GetCurrent(),iterator.GetCurrent());
										break;
									}
								}
							}
						}

					}
				}
			}
			if (sorted.isEmpty())
			{
				a.print();
				std::cout << " - Unreachable position!"<<std::endl;
				return;
			}
				a.print();
				std::cout << std::endl;
				sorted.print();
				return;
			
		}
		std::cout << std::endl;
	}
	
	void Paths()
	{
		ReadMatrix();
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
			{
				Position temp(i, j);
				if (boolarr[i][j] == 1 && !(temp == this->start))
					BFS(temp);
			}
	}
	
};
