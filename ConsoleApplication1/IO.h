#pragma once
#include <iostream>
using namespace std;

 class IO
{
public:
	static void ShowBoard(Board board)
	{
		cout << "-------" << endl;
		for (int i = 0; i < 3; i++)
		{
			cout << "|";
			for (int j = 0; j < 3; j++)
			{
				cout << board.GetCoordinate(i, j) << "|";
			}
			cout << endl;
			cout << "-------" << endl;
		}
	}
	static void ShowShot(int damage, Tank tank1, Tank tank2)// для отображения здоровья и полученого урона танка
	{
		cout << tank1.GetName() << " Good shot !!!" << endl;
		cout << "Tank - " << tank2.GetName() << " Have damage - " << damage << " .HP " << tank2.GetName() << "= " << tank2.GetHP() << endl;

	}
	static void ShowMineStat(Tank tank, Mine mine)
	{
		cout << "Tank - " << tank.GetName() << " Have damage - " << mine.GetDamageMine() << " By mine!!! " << " .HP " << tank.GetName() << "= " << tank.GetHP() << endl;
	}

};