#pragma once
#include "ISensor.h"
class SpeedSensor :
	public ISensor
{
public:
	SpeedSensor() { speed = 0; }
	void update();
	int getSpeed() { return speed; };
private:
	int speed;
};

