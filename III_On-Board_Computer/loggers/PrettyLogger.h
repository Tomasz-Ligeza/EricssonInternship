#pragma once
#include <iostream>
#include "ILogger.h"

class PrettyLogger : public ILogger
{
public:
	PrettyLogger(std::shared_ptr<DataCollector> dataCollector);
	void printLogs();
	void update();
};