#pragma once
#include "ISensor.h"
class FuelLevelSensor : 
	public ISensor
{
public:
	FuelLevelSensor() { fuelLevel = 100; }
	void update();
	int getFuelLevel();
private:
	int fuelLevel;
};

