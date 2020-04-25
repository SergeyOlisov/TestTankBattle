#pragma once
#include <string>
using namespace std;

class Board
{
private:
	char board[3][3];
	int coordinateX;
	int coordinateY;
public:
	Board() //конструктор
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				board[i][j]=' ';
			}
		}
	}

	void ClearBoard() //очистка поля
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				board[i][j] = ' ';
			}
		}
	}

	void SetCoordinate(int x, int y, char move) //заполнение массива значением
	{
		board[x][y] = move;
	}

	int GetCoordinateX()
	{
		return coordinateX;
	}
	int GetCoordinateY()
	{
		return coordinateY;
	}
	char GetCoordinate(int x, int y)
	{
		return board[x][y];
	}
};