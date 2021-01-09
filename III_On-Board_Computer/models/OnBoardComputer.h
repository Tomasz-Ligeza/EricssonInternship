#pragma once
#include <list>

#include "../loggers/ILogger.h"
#include "../sensors/ISensor.h"
enum LoggerType {
	SIMPLE,
	PRETTY
};

class OnBoardComputer
{
public:
	OnBoardComputer(LoggerType loggerType, int period);
	void run();
private:
	int period;
	int refreshSensorsPerios;
	std::shared_ptr<ILogger> logger;
	std::list<std::shared_ptr<ISensor>> sensors;
	std::shared_ptr<DataCollector> dataCollector;

	void initializeSensors();
	void updateSensors();
};

