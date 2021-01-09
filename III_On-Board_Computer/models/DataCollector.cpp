#include "DataCollector.h"

#include <algorithm>

DataCollector::DataCollector()
{
	speed = 0;
	rpm = 0;
	engTemp = 0;
	gearNumber = 0;
	fuelLevel = 0;
	steeringAngle = 0;
	flags = std::bitset<6>("000000");
}

void DataCollector::attach(std::shared_ptr<ILogger> observer)
{
	loggers.push_back(observer);
}

void DataCollector::detach(std::shared_ptr<ILogger> observer)
{
	loggers.remove(observer);
}

void DataCollector::notify()
{
	for (auto& x : loggers) {
		x->update();
	}
}

void DataCollector::updateData()
{
	speed = speedSensor->getSpeed();
	rpm = rpmSensor->getRPM();
	engTemp = engTempSensor->getTemperature();
	gearNumber = gearSensor->getGearNumber();
	fuelLevel = fuelLevelSensor->getFuelLevel();
	steeringAngle = steeringAngleSensor->getSteeringAngle();
	flags = smallerSensors->getFlags();
	notify();
}

int DataCollector::getSpeed()
{
	return speed;
}

int DataCollector::getRPM()
{
	return rpm;
}

int DataCollector::getEngTemp()
{
	return engTemp;
}

int DataCollector::getGearNumber()
{
	return gearNumber;
}

int DataCollector::getFuelLevel()
{
	return fuelLevel;
}

int DataCollector::getSteeringAngle()
{
	return steeringAngle;
}

bool DataCollector::areLightsOn()
{
	return flags[0];
}

bool DataCollector::isLeftBlinkerOn()
{
	return flags[1];
}

bool DataCollector::isRightBlinkerOn()
{
	return flags[2];
}

bool DataCollector::isHandBrakeOn()
{
	return flags[3];
}

bool DataCollector::isOilWrong()
{
	return flags[4];
}

bool DataCollector::isEngineDamaged()
{
	return flags[5];
}

void DataCollector::setSpeedSensor(std::shared_ptr<SpeedSensor> sS)
{
	speedSensor = sS;
}

void DataCollector::setRPMSensor(std::shared_ptr<RPMSensor> rpmS)
{
	rpmSensor = rpmS;
}

void DataCollector::setEngineTemperatureSensor(std::shared_ptr<EngineTemperatureSensor> etS)
{
	engTempSensor = etS;
}

void DataCollector::setFuelLevelSensor(std::shared_ptr<FuelLevelSensor> flS)
{
	fuelLevelSensor = flS;
}

void DataCollector::setSteeringAngleSensor(std::shared_ptr<SteeringAngleSensor> saS)
{
	steeringAngleSensor = saS;
}

void DataCollector::setGearSensor(std::shared_ptr<GearSensor> gS)
{
	gearSensor = gS;
}

void DataCollector::setSmallerSensorsManager(std::shared_ptr<SmallerSensorsManager> ssM)
{
	smallerSensors = ssM;
}
