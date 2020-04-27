#pragma once
#include <string>
using namespace std;

class Tank
{
private:
	std::string name;
	int hp;
	int damage;
	int initiative;
	int ongoingInitiative;
public:
	Tank() //����������� �� ���������
	{
		name = "Tank";
		hp = 100;
		damage = 10;
		initiative = 10;
		ongoingInitiative = initiative;
		
	}

	Tank(std::string name, int hp, int damage,int initiative) //�����������
	{
		this->name = name;
		this->hp = hp;
		this->damage = damage;
		this->initiative = initiative;
		ongoingInitiative = initiative;
		
	}

	void SetHP(int damage) //��������� ����� ������
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
		return damage;
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

};