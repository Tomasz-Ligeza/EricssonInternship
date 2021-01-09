#pragma once
#include "ISensor.h"
class EngineTemperatureSensor :
	public ISensor
{
public:
	EngineTemperatureSensor() { temperature = 0; }
	void update();
	int getTemperature() { return temperature; }
private:
	int temperature;
};

