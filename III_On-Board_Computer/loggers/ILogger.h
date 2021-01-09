#pragma once
#include <string>
#include <memory>
#include "../models/DataCollector.h"
class DataCollector;

class ILogger
{
protected:
	std::shared_ptr<DataCollector> dataCollector;
public:
	virtual void printLogs() = 0;
	virtual void update() = 0;
};

