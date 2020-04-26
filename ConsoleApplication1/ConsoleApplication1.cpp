#include <iostream>
#include "Tank.h"
#include "Board.h"
#include "Mine.h"

using namespace std;

void Move(Tank &name, Board& board, Board& boardMine1,Board& boardMine2, Mine mine, char action);
void Shot(Board& board, Tank& attack, Tank& defence);
void ShowBoard(Board board);
void ShowStat(Tank tank1, Tank tank2);// для отображения здоровья и полученого урона танка
void ShowMap();
void ShowMine(Tank tank, Mine mine);


int main()
{
	Tank tank1("Tank1", 100, 10);
	Tank tank2("Tank2", 100, 10);
	Mine mine1;
	Mine mine2;
	Board board1;
	Board board2;
	Board boardMine1;
	Board boardMine2;

	while (tank1.GetHP() >= 0 && tank2.GetHP() >= 0)
	{
		ShowBoard(board1);
		Move(tank1, board1,boardMine2,boardMine1,mine1,'T');
		Shot(board2, tank1, tank2);
		Move(tank1, board1,boardMine2,boardMine1,mine1,'M');
		
		if(tank2.GetHP()<=0)
		{
			cout << tank2.GetName() << " WIN " << endl;
		}
		system("pause");
		
		system("cls");
		ShowBoard(board2);
		Move(tank2, board2,boardMine1,boardMine2,mine2,'T');
		Shot(board1, tank2, tank1);
		Move(tank2, board2, boardMine1, boardMine2, mine2, 'M');
		
		if(tank1.GetHP()<=0)
		{
			cout << tank1.GetName() << " WIN " << endl;
		}
		system("pause");
		system("cls");
	}
}
void Move(Tank &name, Board& board, Board& boardMine1,Board& boardMine2, Mine mine, char action)
{
		int move;
		bool check = false;
		do
		{
			check = false;
			
			ShowMap();
			if (action == 'T')
			{
				cout << name.GetName() << " Enter your move - ";
			}
			else if (action == 'M')
			{
				cout << name.GetName() << " Enter your mine - ";
			}
			cin >> move;		
			switch (move)
			{
			case 1:
				if (action == 'T')
				{
					
					board.ClearBoard();
					board.SetCoordinate(0, 0, action);
					if (boardMine2.GetCoordinate(0, 0) == 'M')
					{
						name.SetHP(mine.GetDamageMine());
						boardMine2.SetCoordinate(0, 0, ' ');
						ShowMine(name, mine);
					}
				}
				else if(action == 'M') 
				{
					boardMine1.SetCoordinate(0, 0, action);
				}
				break;

			case 2:
				if (action == 'T')
				{
					board.ClearBoard();
					board.SetCoordinate(0, 1, action);
					if (boardMine2.GetCoordinate(0, 1) == 'M')
					{
						name.SetHP(mine.GetDamageMine());
						boardMine2.SetCoordinate(0, 1, ' ');
						ShowMine(name, mine);
					}
				}
				else if (action == 'M')
				{
					boardMine1.SetCoordinate(0, 1, action);
				}
				break;
			case 3:
				if (action == 'T')
				{
					
					board.ClearBoard();
					board.SetCoordinate(0, 2, action);
					if (boardMine2.GetCoordinate(0, 2) == 'M')
					{
						name.SetHP(mine.GetDamageMine());
						boardMine2.SetCoordinate(0, 2, ' ');
						ShowMine(name, mine);
					}
				}
				else if (action == 'M')
				{
					
					boardMine1.SetCoordinate(0, 2, action);
				}
				break;
			case 4:
				if (action == 'T')
				{
					board.ClearBoard();
					board.SetCoordinate(1, 0, action);
					if (boardMine2.GetCoordinate(1, 0) == 'M')
					{
						name.SetHP(mine.GetDamageMine());
						boardMine2.SetCoordinate(1, 0, ' ');
						ShowMine(name, mine);
					}
				}
				else if (action == 'M')
				{
					
					boardMine1.SetCoordinate(1, 0, action);
				}
				break;
			case 5:
				if (action == 'T')
				{
					board.ClearBoard();
					board.SetCoordinate(1, 1, action);
					if (boardMine2.GetCoordinate(1, 1) == 'M')
					{
						name.SetHP(mine.GetDamageMine());
						boardMine2.SetCoordinate(1, 1, ' ');
						ShowMine(name, mine);
					}
				}
				else if (action == 'M')
				{
					
					boardMine1.SetCoordinate(1, 1, action);
				}
				break;
			case 6:
				if (action == 'T')
				{
					board.ClearBoard();
					board.SetCoordinate(1, 2, action);
					if (boardMine2.GetCoordinate(1, 2) == 'M')
					{
						name.SetHP(mine.GetDamageMine());
						boardMine2.SetCoordinate(1, 2, ' ');
						ShowMine(name, mine);
					}
				}
				else if (action == 'M')
				{
					
					boardMine1.SetCoordinate(1, 2, action);
				}
				break;
			case 7:
				if (action == 'T')
				{
					board.ClearBoard();
					board.SetCoordinate(2, 0, action);
					if (boardMine2.GetCoordinate(2, 0) == 'M')
					{
						name.SetHP(mine.GetDamageMine());
						boardMine2.SetCoordinate(2, 0, ' ');
						ShowMine(name, mine);
					}
				}
				else if (action == 'M')
				{
					
					boardMine1.SetCoordinate(2, 0, action);
				}
				break;
			case 8:
				if (action == 'T')
				{
					board.ClearBoard();
					board.SetCoordinate(2, 1, action);
					if (boardMine2.GetCoordinate(2, 1) == 'M')
					{
						name.SetHP(mine.GetDamageMine());
						boardMine2.SetCoordinate(2, 1, ' ');
						ShowMine(name, mine);
					}
				}
				else if (action == 'M')
				{
					
					boardMine1.SetCoordinate(2, 1, action);
				}
				break;
			case 9:
				if (action == 'T')
				{
					board.ClearBoard();
					board.SetCoordinate(2, 2, action);
					if (boardMine2.GetCoordinate(2, 2) == 'M')
					{
						name.SetHP(mine.GetDamageMine());
						boardMine2.SetCoordinate(2, 2, ' ');
						ShowMine(name, mine);
					}
				}
				else if (action == 'M')
				{
					
					boardMine1.SetCoordinate(2, 2, action);
				}
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
			if (board.GetCoordinate(0, 0) == 'T')
			{
				defence.SetHP(attack.GetDamage());
				ShowStat(attack, defence);
			}
			else
			{
				cout << "Miss" << endl;
				break;
			}
			break;
		case 2:
			if (board.GetCoordinate(0, 1) == 'T')
			{
				defence.SetHP(attack.GetDamage());
				ShowStat(attack, defence);
			}
			else
			{
				cout << "Miss" << endl;
				break;
			}
			break;
		case 3:
			if (board.GetCoordinate(0, 2) == 'T')
			{
				defence.SetHP(attack.GetDamage());
				ShowStat(attack, defence);
			}
			else
			{
				cout << "Miss" << endl;
				break;
			}
			break;
		case 4:
			if (board.GetCoordinate(1, 0) == 'T')
			{
				defence.SetHP(attack.GetDamage());
				ShowStat(attack, defence);
			}
			else
			{
				cout << "Miss" << endl;
				break;
			}
			break;
		case 5:
			if (board.GetCoordinate(1, 1) == 'T')
			{
				defence.SetHP(attack.GetDamage());
				ShowStat(attack, defence);
			}
			else
			{
				cout << "Miss" << endl;
				break;
			}
			break;
		case 6:
			if (board.GetCoordinate(1, 2) == 'T')
			{
				defence.SetHP(attack.GetDamage());
				ShowStat(attack, defence);
			}
			else
			{
				cout << "Miss" << endl;
				break;
			}
			break;
		case 7:
			if (board.GetCoordinate(2, 0) == 'T')
			{
				defence.SetHP(attack.GetDamage());
				ShowStat(attack, defence);
			}
			else
			{
				cout << "Miss" << endl;
				break;
			}
			break;
		case 8:
			if (board.GetCoordinate(2, 1) == 'T')
			{
				defence.SetHP(attack.GetDamage());
				ShowStat(attack, defence);
			}
			else
			{
				cout << "Miss" << endl;
				break;
			}
			break;
		case 9:
			if (board.GetCoordinate(2, 2) == 'T')
			{
				defence.SetHP(attack.GetDamage());
				ShowStat(attack, defence);
			}
			else
			{
				cout << "Miss" << endl;
				break;
			}
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

void ShowStat(Tank tank1,Tank tank2)// для отображения здоровья и полученого урона танка
{
	cout << tank1.GetName() << " Good shot !!!" << endl;
	cout << "Tank - " << tank2.GetName() << " Have damage - " << tank1.GetDamage() << " .HP " << tank2.GetName() << "= " << tank2.GetHP() << endl;

}
void ShowMine(Tank tank,Mine mine)
{
	cout << "Tank - " << tank.GetName() << " Have damage - " << mine.GetDamageMine()<<" By mine!!! " << " .HP " << tank.GetName() << "= " << tank.GetHP() << endl;
}


