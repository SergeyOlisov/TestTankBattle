#pragma once
#include <string>
using namespace std;
#include<stdlib.h>//в этом файле содержится функция rand
#include<time.h> //в этом файле содержится функция time


class Tank
{
private:
	std::string name;
	int hp;
	int damage;
	int initiative;
	int ongoingInitiative;
	int coordinateX;
	int coordinateY;
public:
	Tank() //конструктор по умолчанию
	{
		name = "Tank";
		hp = 100;
		damage = 6;
		initiative = 10;
		ongoingInitiative = initiative;
		coordinateX = 1;
		coordinateY = 1;
	}

	Tank(std::string name, int hp, int damage,int initiative) //конструктор
	{
		this->name = name;
		this->hp = hp;
		this->damage = damage;
		this->initiative = initiative;
		ongoingInitiative = initiative;
		coordinateX = 1;
		coordinateY = 1;		
	}

	void SetHP(int damage) //получение урона танком
	{
		hp -= damage;
	}
	void SetInitiative(int initiative)
	{
		ongoingInitiative += initiative;
	}
	void ZeroingInitiative()
	{
		ongoingInitiative = 0;
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
		srand(time(0));
		int critical = 1+rand() % 5;
		int probability = 5 + rand() % damage;
		if(critical==5)
		{
			return 2*probability;
		}
		else 
		{
			return probability;
		}
	}
	
	string GetName()
	{
		return name;
	}
	int GetInitiative()
	{
		return initiative;
	}
	int GetOngoingIniciative()
	{
		return ongoingInitiative;
	}
	int GetCoordinateX()
	{
		return coordinateX;
	}
	int GetCoordinateY()
	{
		return coordinateY;
	}
	void SetCoordinateX(int x)
	{
		 coordinateX = x;
	}
	void SetCoordinateY(int y)
	{	
		 coordinateY = y;
	}


};