#include "GearSensor.h"

void GearSensor::update()
{
	gear = (gear + 1) % 5;
}

int GearSensor::getGearNumber()
{
	return gear;
}
