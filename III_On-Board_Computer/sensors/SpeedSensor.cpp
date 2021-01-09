#include "SpeedSensor.h"

void SpeedSensor::update()
{
	speed = (speed + 3) % 99;
}
