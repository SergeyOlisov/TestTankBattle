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
	Tank() //конструктор по умолчанию
	{
		name = "Tank";
		hp = 100;
		damage = 10;
	}

	Tank(string name, int hp, int damage) //конструктор
	{
		this->name = name;
		this->hp = hp;
		this->damage = damage;
	}

	void SetHP(int damage) //получение урона танком
	{
		this->hp -= damage;
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