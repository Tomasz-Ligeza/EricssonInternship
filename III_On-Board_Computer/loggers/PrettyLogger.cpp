#include "PrettyLogger.h"
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
		<< dataCollector->getEngTemp() << " *C\t"
		<< std::setw(4) << dataCollector->getRPM() << " rpm\t\t"
		<< dataCollector->getSpeed() << " km/h\t"
		<< dataCollector->getFuelLevel() << " %oF\n\t"
		<< (dataCollector->isOilWrong() ? "OIL" : "---") << "\t"

		<< dataCollector->getSteeringAngle() << "*\t"
		<< dataCollector->getGearNumber() << ".G\t"

		<< (dataCollector->isEngineDamaged() ? "ENG" : "---") << "\n\n";
}

void PrettyLogger::update()
{
	printLogs();
}
