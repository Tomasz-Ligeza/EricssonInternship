#pragma once
#include "ISensor.h"
class SteeringAngleSensor :
	public ISensor
{
public:
	SteeringAngleSensor() { angle = 0; }
	void update();
	int getSteeringAngle() { return angle; }
private:
	int angle;
};

