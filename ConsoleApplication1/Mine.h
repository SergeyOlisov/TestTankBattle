#pragma once
#include <string>

using namespace std;

class Mine
{
private:
	int counter = 0;
	string name = "Mine";
	int damageMine = 15;
public:
	Mine() {}
	void ActivateCounter()
	{
		counter = 5;
	}
	void Countdown()
	{
		counter--;
		if (counter < 0)
		{
			counter = 0;
		}
	}

	int GetDamageMine() 
	{
		return damageMine;
	}
	int GetCounter() 
	{
		return counter;
	}



};