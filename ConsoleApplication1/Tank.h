#pragma once
using namespace std;
#include <string>

class Tank
{
private:
	string name;
	int hp;
	int damage;
public:
	Tank() //����������� �� ���������
	{
		name = "Tank";
		hp = 100;
		damage = 10;
	}

	Tank(string name, int hp, int damage) //�����������
	{
		this->name = name;
		this->hp = hp;
		this->damage = damage;
	}

	void SetHP(int damage) //��������� ����� ������
	{
		hp -= damage;
	}

	void SetHealHP(int heal)
	{
		hp += heal;
		if (hp > 100)
		{
			hp = 100;
		}
	}
	
	int GetHP()
	{
		return hp;
	}
	int GetDamage()
	{
		return damage;
	}
	string GetName()
	{
		return name;
	}

};