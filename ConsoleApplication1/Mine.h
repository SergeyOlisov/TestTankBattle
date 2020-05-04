#pragma once
#include <string>
#include <conio.h>
#include "IO.h"
using namespace std;

class Mine
{
private:
	int counter = 0;
	string name = "Mine";
	int damageMine = 15;
	int coordinateX=1;
	int coordinateY=1;
public:
	Mine() {}
	void ActivateCounter()
	{
		counter = 5;
	}
	void Countdown()
	{
		counter--;
		if (counter < 0)
		{
			counter = 0;
		}
	}
	void SetCoordinateMineX(int x)
	{
		coordinateX = x;

	}
	void SetCoordinateMineY(int y)
	{
		coordinateY = y;

	}

	int GetDamageMine() 
	{
		return damageMine;
	}
	int GetCounter() 
	{
		return counter;
	}
	int GetCoordinateX()
	{
		return coordinateX;
	}
	int GetCoordinateY()
	{
		return coordinateY;
	}

	static void MoveMine(Mine& mine1, Mine& mine2, Board& board1, Board& board2,Tank tank)
	{

		char move;
		do
		{
			
			board1.TempBoard(mine1.GetCoordinateX(), mine1.GetCoordinateY(), '*');
			IO::ShowBoard(board1, tank);
			move = _getch();
			switch (move)
			{
			case 's':
				MoveDown(mine1, board1);
				break;
			case 'w':
				MoveUp(mine1, board1);
				break;
			case 'a':
				MoveLeft(mine1, board1);
				break;
			case 'd':
				MoveRight(mine1, board1);
				break;
			}
		} while (move != 'p');
	}

	static void MoveDown(Mine& mine1, Board& board)
	{
		if (mine1.GetCoordinateX() == board.SIZEBOARD - 1)
		{
			board.SetCoordinate(mine1.GetCoordinateX(), mine1.GetCoordinateY(), '*');
		}
		if (mine1.GetCoordinateX() < board.SIZEBOARD - 1)
		{
			board.SetCoordinate(mine1.GetCoordinateX() + 1, mine1.GetCoordinateY(), '*');
			mine1.SetCoordinateMineX(mine1.GetCoordinateX() + 1);
		}
	}
	static void MoveUp(Mine& mine1, Board& board)
	{
		if (mine1.GetCoordinateX() == 0)
		{
			board.SetCoordinate(mine1.GetCoordinateX(), mine1.GetCoordinateY(), '*');
		}
		if (mine1.GetCoordinateX() > 0)
		{
			board.SetCoordinate(mine1.GetCoordinateX() - 1, mine1.GetCoordinateY(), '*');
			mine1.SetCoordinateMineX(mine1.GetCoordinateX() - 1);
		}
	}
	static void MoveRight(Mine& mine1, Board& board)
	{
		if (mine1.GetCoordinateY() == board.SIZEBOARD - 1)
		{
			board.SetCoordinate(mine1.GetCoordinateX(), mine1.GetCoordinateY(), '*');
		}
		if (mine1.GetCoordinateY() < board.SIZEBOARD - 1)
		{
			board.SetCoordinate(mine1.GetCoordinateX(), mine1.GetCoordinateY() + 1, '*');
			mine1.SetCoordinateMineY(mine1.GetCoordinateY() + 1);
		}
	}
	static void MoveLeft(Mine& mine1, Board& board)
	{
		if (mine1.GetCoordinateY() == 0)
		{
			board.SetCoordinate(mine1.GetCoordinateX(), mine1.GetCoordinateY(), '*');
		}
		if (mine1.GetCoordinateY() > 0)
		{
			board.SetCoordinate(mine1.GetCoordinateX(), mine1.GetCoordinateY() - 1, '*');
			mine1.SetCoordinateMineY(mine1.GetCoordinateY() - 1);
		}
	}

};