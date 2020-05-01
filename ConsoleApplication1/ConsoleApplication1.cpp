#include <iostream>
#include "Tank.h"
#include "Board.h"
#include "Mine.h"
#include "Heal.h"

using namespace std;

void Move(Tank &name, Board& board, Board& boardMine1,Board& boardMine2, Mine mine, char action);
void Shot(Board& board, Tank& attack, Tank& defence);
void ShowBoard(Board board);
void ShowShot(int damage, Tank tank1, Tank tank2);// для отображения здоровья и полученого урона танка
void ShowMap();
void ShowMineStat(Tank tank, Mine mine);
void HealTank(Tank& tank, Heal& heal);
void MoveTank(Tank &tank,Board &board, Board &boardMine);
void MoveMine(Tank& tank, Board& boardMine);
void CheckShot(Board& board, Tank& attak, Tank& defence,int x,int y);
void CheckMine(Board& boardDefenceMine, Tank& tankDefence, Mine mine, int x, int y);


int main()
{
	Tank tank1("Tank1", 100, 6, 10);
	Tank tank2("Tank2", 100, 6, 10);
	Mine mine1;
	Mine mine2;
	Heal heal1;
	Heal heal2;
	Board board1;
	Board board2;
	Board boardMine1;
	Board boardMine2;

	while (tank1.GetHP() >= 0 && tank2.GetHP() >= 0)
	{
		MoveTank(tank1, board1,boardMine1);
		MoveMine(tank1, boardMine2);
		Shot(board2, tank1, tank2);
		system("pause");
		system("cls");

		MoveTank(tank2, board2,boardMine2);
		MoveMine(tank2, boardMine1);
		Shot(board1, tank2, tank1);
		system("pause");
		system("cls");
		/*if (tank1.GetOngoingIniciative() >= 10) 
		{
			//Ходит первый игрок
			ShowBoard(board1);
			Move(tank1, board1, boardMine2, boardMine1, mine1, 'T');
			Shot(board2, tank1, tank2);
			system("pause");
			system("cls");
			if (mine1.GetCounter() > 0)
			{
				cout << "Mine reload after " << mine1.GetCounter() << " turns " << endl;
			}
			else {
				Move(tank1, board1, boardMine2, boardMine1, mine1, 'M');
				mine1.ActivateCounter();
			}
			mine1.Countdown();
			HealTank(tank1, heal1);

			if (tank2.GetHP() <= 0)
			{
				cout << tank2.GetName() << " WIN " << endl;
			}
			system("pause");
			system("cls");
			tank1.ZeroingInitiative();
		}
		else if(tank1.GetOngoingIniciative()<10)
		{

			tank1.SetInitiative(tank1.GetInitiative());
		}
		
		
		//Ходит второй игрок
		ShowBoard(board2);
		Move(tank2, board2,boardMine1,boardMine2,mine2,'T');
		Shot(board1, tank2, tank1);
		system("pause");
		system("cls");

		if (mine2.GetCounter() > 0)
		{
			cout << "Mine reload after " << mine2.GetCounter() << " turns " << endl;
		} else {
			Move(tank2, board2, boardMine1, boardMine2, mine2, 'M');
			mine2.ActivateCounter();
		}
		mine2.Countdown();
		HealTank(tank2, heal2);
		
		if(tank1.GetHP()<=0)
		{
			cout << tank1.GetName() << " WIN " << endl;
		}
		system("pause");
		system("cls");*/
	}
}



void MoveTank(Tank &tank,Board &board, Board &boardMine)
{
	    Mine mine;
	    ShowBoard(board);
        int move;
		bool check = false;
		do
		{
			check = false;
			
			ShowMap();
			
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
void ShowBoard(Board board)
{
	cout << "-------" << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << "|";
		for (int j = 0; j < 3; j++)
		{
			cout << board.GetCoordinate(i,j) << "|";
		}
		cout << endl;
		cout << "-------" << endl;
	}
}
void ShowMap()
{
	int count= 1;
	cout << endl;
	cout << "-------" << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << "|";
		for (int j = 0; j < 3; j++)
		{
			cout << count << "|";
			count++;

		}
		cout << endl;
		cout << "-------" << endl;
	}
}

void ShowShot (int damage,Tank tank1, Tank tank2)// для отображения здоровья и полученого урона танка
{
	cout << tank1.GetName() << " Good shot !!!" << endl;
	cout << "Tank - " << tank2.GetName() << " Have damage - " << damage << " .HP " << tank2.GetName() << "= " << tank2.GetHP() << endl;

}
void ShowMineStat(Tank tank,Mine mine)
{
	cout << "Tank - " << tank.GetName() << " Have damage - " << mine.GetDamageMine() <<" By mine!!! " << " .HP " << tank.GetName() << "= " << tank.GetHP() << endl;
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
		ShowMap();
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
		ShowShot(damage, attack, defence);
	}
	else
	{
		cout << "Miss" << endl;
	}
}
void CheckMine(Board &boardDefenceMine,Tank &tankDefence, Mine mine, int x, int y)
{
	if (boardDefenceMine.GetCoordinate(x, y) == 'M')
	{
		tankDefence.SetHP(mine.GetDamageMine());
		boardDefenceMine.SetCoordinate(x, y, ' ');
		ShowMineStat(tankDefence, mine);
		cout << "Test";
	}
}


