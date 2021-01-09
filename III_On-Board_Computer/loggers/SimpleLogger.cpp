#include "SimpleLogger.h"
#include <iostream>
#include <iomanip>

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
	std::cout << std::setw(2) << dataCollector->getSpeed() << " km/h; "
		<< std::setw(4) << dataCollector->getRPM() << " rmp; "
		<< std::setw(3) << dataCollector->getEngTemp() << " *C; "
		<< dataCollector->getGearNumber() << ".G "
		<< std::setw(3) << dataCollector->getFuelLevel() << "%oF; "
		<< std::setw(3) << dataCollector->getSteeringAngle() << "* "
		<< std::noboolalpha
		<< dataCollector->areLightsOn()
		<< dataCollector->isLeftBlinkerOn()
		<< dataCollector->isRightBlinkerOn()
		<< dataCollector->isHandBrakeOn()
		<< dataCollector->isOilWrong()
		<< dataCollector->isEngineDamaged()
		<< " <L/LB/RB/H/O/E>\n";
}
