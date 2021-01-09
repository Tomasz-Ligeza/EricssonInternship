#include "EngineTemperatureSensor.h"

void EngineTemperatureSensor::update()
{
	temperature = (temperature + 1) % 99;
}
