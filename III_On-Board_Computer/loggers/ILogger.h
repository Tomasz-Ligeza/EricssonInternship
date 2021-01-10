#pragma once
#include <string>
#include <memory>
#include "../models/DataCollector.h"
class DataCollector;

/*
	ILogger abstract class is base class for SimpleLogger and PrettyLogger.
	Both are responsible for printing out logs.
	
	DataCollector notifies them in order to print out data.
*/

class ILogger
{
protected:
	std::shared_ptr<DataCollector> dataCollector;
public:
	virtual void printLogs() = 0;
	virtual void update() = 0;
};

