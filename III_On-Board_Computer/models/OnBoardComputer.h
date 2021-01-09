#pragma once
#include <list>

#include "../loggers/ILogger.h"
#include "../sensors/ISensor.h"

class OnBoardComputer
{
public:
	OnBoardComputer();
	void run();
	void updateSensors();
private:
	std::shared_ptr<ILogger> logger;
	std::list<std::shared_ptr<ISensor>> sensors;
	std::shared_ptr<DataCollector> dataCollector;
};

