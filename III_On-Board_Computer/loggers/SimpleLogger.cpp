#include "SimpleLogger.h"
#include <iostream>

SimpleLogger::SimpleLogger(std::shared_ptr<DataCollector> dataCollector)
{
	this->dataCollector = dataCollector;
}

void SimpleLogger::update()
{
	printLogs();
}

void SimpleLogger::printLogs()
{
	std::cout << dataCollector->getSpeed() << " km/h; "
		<< dataCollector->getRPM() << " rmp; "
		<< dataCollector->getEngTemp() << " *C; "
		<< dataCollector->getGearNumber() << ".G "
		<< dataCollector->getFuelLevel() << "%oF; "
		<< dataCollector->getSteeringAngle() << "* "
		<< std::noboolalpha
		<< dataCollector->areLightsOn()
		<< dataCollector->isLeftBlinkerOn()
		<< dataCollector->isRightBlinkerOn()
		<< dataCollector->isHandBrakeOn()
		<< dataCollector->isOilWrong()
		<< dataCollector->isEngineDamaged()
		<< " <L/LB/RB/H/O/E>\n";
}
