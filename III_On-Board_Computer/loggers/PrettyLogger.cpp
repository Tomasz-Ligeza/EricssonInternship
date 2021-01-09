#include "PrettyLogger.h"
#include <iostream>
#include <iomanip>

PrettyLogger::PrettyLogger(std::shared_ptr<DataCollector> dataCollector)
{
	this->dataCollector = dataCollector;
}

void PrettyLogger::printLogs()
{
	std::cout << "\t" << (dataCollector->areLightsOn() ? "=O" : "--") << "\t"
		<< (dataCollector->isLeftBlinkerOn() ? "<=" : "--") << "\t"
		<< (dataCollector->isRightBlinkerOn() ? "=>" : "--") << "\t"
		<< (dataCollector->isHandBrakeOn() ? "(!)" : "---") << "\n"
		<< "  " << std::setw(2) << dataCollector->getEngTemp() << " *C\t"
		<< std::setw(4) << dataCollector->getRPM() << " rpm\t"
		<< std::setw(2) << dataCollector->getSpeed() << " km/h\t"
		<< std::setw(3) << dataCollector->getFuelLevel() << " %oF\n\t"
		<< (dataCollector->isOilWrong() ? "OIL" : "---") << "\t"

		<< std::setw(3) << dataCollector->getSteeringAngle() << "*\t"
		<< dataCollector->getGearNumber() << ".G\t"

		<< (dataCollector->isEngineDamaged() ? "ENG" : "---") << "\n\n";
}

void PrettyLogger::update()
{
	printLogs();
}
