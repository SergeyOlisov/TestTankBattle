#pragma once
#include "Tank.h"
#include "Board.h"
#include "IO.h"
#include "Mine.h"
#include <conio.h>
using namespace std;
class MoveTank
{
public:
	static void Move(Tank& tank1,Tank& tank2, Board& board)
	{
		char move;
		system("cls");
		board.ClearBoard();
		board.TempBoard(tank1.GetCoordinateX(), tank1.GetCoordinateY(), 'T');
		board.TempBoard(tank2.GetCoordinateX(), tank2.GetCoordinateY(), 'T');
		IO::ShowBoard(board, tank1);
		cout << "S-Down,W-MoveUp,A-left,D-Right" << endl;
		move = _getch();
		switch (move)
		{
		case 's':
			MoveDown(tank1, board);
			break;
		case 'w':
			MoveUp(tank1, board);
			break;
		case 'a':
			MoveLeft(tank1, board);
			break;
		case 'd':
			MoveRight(tank1, board);
			break;
		}
	}

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
		
		if (boardDefenceMine.GetCoordinate(x, y) == 'M')
		{
			tankDefence.SetHP(mine.GetDamageMine());
			boardDefenceMine.SetCoordinate(x, y, ' ');
			IO::ShowMineStat(tankDefence, mine);
		}
	}
};