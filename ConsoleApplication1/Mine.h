#pragma once
#include <string>

using namespace std;

class Mine
{
private:
	int counter = 0;
	string name = "Mine";
	int damageMine = 15;
	int coordinateX;
	int coordinateY;
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
	int GetCoordinateX()
	{
		return coordinateX;
	}
	int GetCoordinateY()
	{
		return coordinateY;
	}


};