#include "FuelLevelSensor.h"
#include <math.h>

void FuelLevelSensor::update()
{
	fuelLevel = (abs(fuelLevel - 1) % 100);
}

int FuelLevelSensor::getFuelLevel()
{
	return fuelLevel;
}
