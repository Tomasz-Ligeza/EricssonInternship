#pragma once
#include "ILogger.h"

class SimpleLogger : public ILogger
{
private: 
	void printLogs();
public:
	SimpleLogger(std::shared_ptr<DataCollector> dataCollector);
	void update();
};

