#pragma once
#include <bitset>
#include "ISensor.h"


class SmallerSensorsManager :
	public ISensor
{
public:
	SmallerSensorsManager();
	void update();
	std::bitset<6> getFlags() { return sensorsFlags; }
private:
	std::bitset<6> sensorsFlags;
};

