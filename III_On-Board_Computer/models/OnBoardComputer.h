#pragma once
#include <list>

#include "../loggers/ILogger.h"
#include "../sensors/ISensor.h"

/*
	enum class created in order to choose way of printing logs.
*/

enum class LoggerType {
	SIMPLE,
	PRETTY
};

/*
	OnBoardComputer is a class that contains chosen logger,
	sensors, and dataCollector that reads from sensors.

	Sensors shouldn`t be kept here, but I have to update their temperature etc.
	As I`ve said before, they just imitate real work of sensors.
*/

class OnBoardComputer
{
public:
	OnBoardComputer(LoggerType loggerType, int period);
	void run();
private:
	int period;
	int refreshSensorsPeriod;
	std::shared_ptr<ILogger> logger;
	std::list<std::shared_ptr<ISensor>> sensors;
	std::shared_ptr<DataCollector> dataCollector;

	void initializeSensors();
	
	/*
		This function in normal situation wouldn`t exist,
		because sensors read data from "environment" and not generate them.
	*/
	void updateSensors();
};

