#include "SteeringAngleSensor.h"

void SteeringAngleSensor::update()
{
	static int diff = 15;
	if (-360 >= angle || angle >= 360) {
		diff *= -1;
	}
	angle += diff;
}