#pragma once
#include "Tank.h"
#include "Board.h"
#include "IO.h"
#include "Mine.h"
using namespace std;
class Move
{
	
public:
	Move() {};
	void MoveTank(Tank& tank, Board& board, Board& boardMine)
	{
		IO io;
		Mine mine;
		io.ShowBoard(board);
		int move;
		bool check = false;
		do
		{
			check = false;

			io.ShowMap();

			cin >> move;
			switch (move)
			{
			case 1:
				board.ClearBoard();
				board.SetCoordinate(0, 0, 'T');
				CheckMine(boardMine, tank, mine, 0, 0);
				break;

			case 2:
				board.ClearBoard();
				board.SetCoordinate(0, 1, 'T');
				CheckMine(boardMine, tank, mine, 0, 1);
				break;
			case 3:
				board.ClearBoard();
				board.SetCoordinate(0, 2, 'T');
				CheckMine(boardMine, tank, mine, 0, 2);

				break;
			case 4:
				board.ClearBoard();
				board.SetCoordinate(1, 0, 'T');
				CheckMine(boardMine, tank, mine, 1, 0);
				break;
			case 5:
				board.ClearBoard();
				board.SetCoordinate(1, 1, 'T');
				CheckMine(boardMine, tank, mine, 1, 1);
				break;
			case 6:
				board.ClearBoard();
				board.SetCoordinate(1, 2, 'T');
				CheckMine(boardMine, tank, mine, 1, 2);
				break;
			case 7:
				board.ClearBoard();
				board.SetCoordinate(2, 0, 'T');
				CheckMine(boardMine, tank, mine, 2, 0);
			case 8:
				board.ClearBoard();
				board.SetCoordinate(2, 1, 'T');
				CheckMine(boardMine, tank, mine, 2, 1);
				break;
			case 9:
				board.ClearBoard();
				board.SetCoordinate(2, 2, 'T');
				CheckMine(boardMine, tank, mine, 2, 2);
				break;
			default:
				cout << "Wrong ccordinate";
				check = true;
			}
		} while (check);

	}

	void CheckMine(Board& boardDefenceMine, Tank& tankDefence, Mine mine, int x, int y)
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