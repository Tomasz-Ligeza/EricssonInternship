#include "SmallerSensorsManager.h"

SmallerSensorsManager::SmallerSensorsManager()
{
	for (int i = 0; i < sensorsFlags.size() ; i++) {
		sensorsFlags[i] = i % 2;
	}
}

void SmallerSensorsManager::update()
{
	std::bitset<6> flagsCopy = sensorsFlags;
	for (int i = 0; i < sensorsFlags.size(); i++) {
		sensorsFlags[i] = flagsCopy[(i + 1) % sensorsFlags.size()];
	}
}
