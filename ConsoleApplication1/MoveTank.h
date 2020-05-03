#pragma once
#include "Tank.h"
#include "Board.h"
#include "IO.h"
#include "Mine.h"
using namespace std;
class MoveTank
{
	
public:
	
	/*void MoveTank(Tank& tank, Board& board, Board& boardMine)
	{
		
	char move;
	int x = 1;
	int y = 1;
	int coup = 0;
	board.SetCoordinate(x, y,'T');

	}*/
	static void MoveDown(Tank& tank, Board& board)
	{
		if (tank.GetCoordinateX() == board.SIZEBOARD-1)
		{
			board.SetCoordinate(tank.GetCoordinateX(), tank.GetCoordinateY(), 'T');
		}
		if (tank.GetCoordinateX()  <  board.SIZEBOARD-1)
		{
			board.SetCoordinate(tank.GetCoordinateX() + 1, tank.GetCoordinateY(), 'T');
			tank.SetCoordinateX(tank.GetCoordinateX() + 1);
		}
	}
	static void MoveUp(Tank& tank, Board& board)
	{
		if (tank.GetCoordinateX() == 0)
		{
			board.SetCoordinate(tank.GetCoordinateX(), tank.GetCoordinateY(), 'T');
		}
		if (tank.GetCoordinateX()  >  0)
		{
			board.SetCoordinate(tank.GetCoordinateX() -1, tank.GetCoordinateY(), 'T');
			tank.SetCoordinateX(tank.GetCoordinateX() -1);
		}
	}
	static void MoveRight(Tank& tank, Board& board)
	{
		if (tank.GetCoordinateY() == board.SIZEBOARD-1)
		{
			board.SetCoordinate(tank.GetCoordinateX(), tank.GetCoordinateY(), 'T');
		}
		if (tank.GetCoordinateY()  <  board.SIZEBOARD-1)
		{
			board.SetCoordinate(tank.GetCoordinateX(), tank.GetCoordinateY()+1, 'T');
			tank.SetCoordinateY(tank.GetCoordinateY()+1);
		}
	}
	static void MoveLeft(Tank& tank, Board& board)
	{
		if (tank.GetCoordinateY() ==0)
		{
			board.SetCoordinate(tank.GetCoordinateX(), tank.GetCoordinateY(), 'T');
		}
		if (tank.GetCoordinateY()  > 0)
		{
			board.SetCoordinate(tank.GetCoordinateX(), tank.GetCoordinateY()-1, 'T');
			tank.SetCoordinateY(tank.GetCoordinateY()-1);
		}
	}
	
	
	static void CheckMine(Board& boardDefenceMine, Tank& tankDefence, Mine mine, int x, int y)
	{
		IO io;
		if (boardDefenceMine.GetCoordinate(x, y) == 'M')
		{
			tankDefence.SetHP(mine.GetDamageMine());
			boardDefenceMine.SetCoordinate(x, y, ' ');
			io.ShowMineStat(tankDefence, mine);

		}
	}


};