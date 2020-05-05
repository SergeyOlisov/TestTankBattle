﻿#include <iostream>
#include "Tank.h"
#include "Board.h"
#include "Mine.h"
#include "Heal.h"
#include "IO.h"
#include "MoveTank.h"
#include <conio.h>
#include <stdio.h>
#include <Windows.h>

using namespace std;

void Move(Tank &name, Board& board, Board& boardMine1,Board& boardMine2, Mine mine, char action);
void Shot(Board& board, Tank& attack, Tank& defence);
void HealTank(Tank& tank, Heal& heal);
void MoveMine(Tank& tank, Board& boardMine);
void CheckShot(Board& board, Tank& attak, Tank& defence,int x,int y);

//void CheckMine(Board& boardDefenceMine, Tank& tankDefence, Mine mine, int x, int y);
  
int main()
{
	IO io;
	Tank tank1("Tank1", 100, 6, 10, 1, 1, 1);
	Tank tank2("Tank2", 100, 6, 10, 2, 2, 2);
	Mine mine1;
	Mine mine2;
	Heal heal1;
	Heal heal2;
	Board board1;
	Board board2;
	Board boardMine1;
	Board boardMine2;
	
	
	char move;
	
	
	while (tank1.GetHP() >= 0 && tank2.GetHP() >= 0)
	{
		board1.TempBoard(tank1.GetCoordinateX(), tank1.GetCoordinateY(), 'T');
		board2.TempBoard(tank2.GetCoordinateX(), tank2.GetCoordinateY(), 'T');
		system("cls");
		IO::ShowBoard(board1, tank1);
		IO::ShowBoard(board2, tank2);
		cout << "S-Down,W-MoveUp,A-left,D-Right" << endl;
		MoveTank::Move(tank1, tank2, board1, board2);
		board1.TempBoard(tank1.GetCoordinateX(), tank1.GetCoordinateY(), 'T');
		board2.TempBoard(tank2.GetCoordinateX(), tank2.GetCoordinateY(), 'T');
		system("cls");
		IO::ShowBoard(board1, tank1);
		IO::ShowBoard(board2, tank2);

		Mine::MoveMine(mine1, mine2, boardMine1, boardMine2,tank1);
		IO::ShowBoard(boardMine2, tank1);
		board1.TempBoard(tank1.GetCoordinateX(), tank1.GetCoordinateY(), 'T');
		board2.TempBoard(tank2.GetCoordinateX(), tank2.GetCoordinateY(), 'T');
		system("cls");
		IO::ShowBoard(board1, tank1);
		IO::ShowBoard(board2, tank2);
		cout << "S-Down,W-MoveUp,A-left,D-Right" << endl;
		MoveTank::Move(tank2, tank1, board2, board1);
		cout << "Move mine" <<endl;
		
	}
}



//void MoveTank(Tank &tank,Board &board, Board &boardMine)
//{
//	    IO io;
//	    Mine mine;
//		io.ShowBoard(board);
//        int move;
//		bool check = false;
//		do
//		{
//			check = false;
//			
//			io.ShowMap();
//			
//			cin >> move;		
//			switch (move)
//			{
//			case 1:					
//					board.ClearBoard();
//					board.SetCoordinate(0, 0, 'T');
//					CheckMine(boardMine, tank, mine, 0, 0);
//				break;
//
//			case 2:
//				    board.ClearBoard();
//					board.SetCoordinate(0, 1, 'T');
//					CheckMine(boardMine, tank, mine, 0, 1);
//				break;
//			case 3:
//				    board.ClearBoard();
//					board.SetCoordinate(0, 2, 'T');
//					CheckMine(boardMine, tank, mine, 0, 2);
//				
//				break;
//			case 4:
//				 board.ClearBoard();
//			     board.SetCoordinate(1, 0, 'T');
//				 CheckMine(boardMine, tank, mine, 1, 0);
//				break;
//			case 5:
//				 board.ClearBoard();
//			     board.SetCoordinate(1, 1, 'T');
//				 CheckMine(boardMine, tank, mine, 1, 1);
//				break;
//			case 6:
//				board.ClearBoard();
//			    board.SetCoordinate(1, 2, 'T');
//				CheckMine(boardMine, tank, mine, 1, 2);
//				break;
//			case 7:
//				board.ClearBoard();
//			    board.SetCoordinate(2, 0, 'T');
//				CheckMine(boardMine, tank, mine, 2, 0);
//			case 8:
//				board.ClearBoard();
//			    board.SetCoordinate(2, 1, 'T');
//				CheckMine(boardMine, tank, mine, 2, 1);
//				break;
//			case 9:
//				board.ClearBoard();
//			    board.SetCoordinate(2, 2, 'T');
//				CheckMine(boardMine, tank, mine, 2, 2);
//				break;
//			default:
//				cout << "Wrong ccordinate";
//				check = true;
//			}
//		} while (check);
//
//}


void Shot(Board& board, Tank& attack, Tank& defence)
{
	cout << attack.GetName() << " make you Shot -  ";
	int shot;
	bool check = false;
	
	do
	{
		check = false;
		cin >> shot;
		switch (shot)
		{
		case 1:
			CheckShot(board, attack, defence, 0, 0);
			break;
		case 2:
			CheckShot(board, attack, defence, 0, 1);
			break;
		case 3:
			CheckShot(board, attack, defence, 0, 2);
			break;
		case 4:
			CheckShot(board, attack, defence, 1, 0);
			break;
		case 5:
			CheckShot(board, attack, defence, 1, 1);
			break;
		case 6:
			CheckShot(board, attack, defence, 1, 2);
			break;
		case 7:
			CheckShot(board, attack, defence, 2, 0);
			break;
		case 8:
			CheckShot(board, attack, defence, 2, 1);
			break;
		case 9:
			CheckShot(board, attack, defence, 2, 2);
			break;
		default:
			check = true;
			cout << "Wrong coordinate!!! ";
		} 
	} while (check);
}


void HealTank(Tank& tank,Heal &heal)
{
	if (heal.GetCounter() > 0)
	{
		cout << "Wait for reload your Heal "<< heal.GetCounter() << endl;


	}
	else 
	{
		char move;
		cout << "Heal you tank? y - yes, n - no" << endl;
		cin >> move;
		switch (move)
		{
		case 'y':
			tank.SetHealHP(heal.GetHeal());
			heal.SetCounter();
			cout << "Your HP =" << tank.GetHP() <<" After heal "<< endl;

			break;
		default:
			break;
		}	
	}
}

void MoveMine(Tank& tank, Board& boardMine)
{
	int move;
	bool check = false;
	do
	{
		check = false;
		cout << tank.GetName() << " Enter your mine - ";
		
		cin >> move;
		switch (move)
		{
		case 1:		
				boardMine.SetCoordinate(0, 0, 'M');		
			break;

		case 2:		
				boardMine.SetCoordinate(0, 1, 'M');		
			break;
		case 3:
				boardMine.SetCoordinate(0, 2, 'M');
			break;
		case 4:
				boardMine.SetCoordinate(1, 0, 'M');
			break;
		case 5:
				boardMine.SetCoordinate(1, 1, 'M');
			break;
		case 6:
				boardMine.SetCoordinate(1, 2, 'M');
			break;
		case 7:
				boardMine.SetCoordinate(2, 0, 'M');
			break;
		case 8:
				boardMine.SetCoordinate(2, 1, 'M');
			break;
		case 9:
				boardMine.SetCoordinate(2, 2, 'M');
			break;
		default:
			cout << "Wrong ccordinate";
			check = true;
		}
	} while (check);
}

void CheckShot(Board& board, Tank& attack, Tank& defence, int x, int y)
{
	
	if (board.GetCoordinate(x, y) == 'T')
	{
		int damage;
		damage = attack.GetDamage();
		if(damage>10)
		{
			cout << "!!!Critical damage!!!" << endl;
		}
		defence.SetHP(damage);
	//	io.ShowShot(damage, attack, defence);
	}
	else
	{
		cout << "Miss" << endl;
	}
}
//void CheckMine(Board &boardDefenceMine,Tank &tankDefence, Mine mine, int x, int y)
//{
//	IO io;
//	if (boardDefenceMine.GetCoordinate(x, y) == 'M')
//	{
//		tankDefence.SetHP(mine.GetDamageMine());
//		boardDefenceMine.SetCoordinate(x, y, ' ');
//		io.ShowMineStat(tankDefence, mine);
//		
//	}
//}


