#pragma once
#include "ISensor.h"
class GearSensor : 
	public ISensor
{
public:
	GearSensor() { gear = 0; }
	void update();
	int getGearNumber();
private:
	int gear;
};

