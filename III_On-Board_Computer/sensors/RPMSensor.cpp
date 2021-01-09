#include "RPMSensor.h"

void RPMSensor::update()
{
	rpm = (rpm + 450) % 5000;
}
