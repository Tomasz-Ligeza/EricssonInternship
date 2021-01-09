#pragma once
#include "ISensor.h"
class RPMSensor :
	public ISensor
{
public:
	RPMSensor() { rpm = 0; }
	void update();
	int getRPM() { return rpm; }
private:
	int rpm;
};

