#pragma once
#include <memory>
#include <bitset>
#include <list>
#include "../loggers/ILogger.h"
#include "../sensors/Sensors.h"

class ILogger;

/*
	DataCollector class is a typical "Subject" class from Observer pattern.
	It takes care of receiving data from all sensors, and notifies logger
	when data is refreshed.

	It contains pointers to all sensors.
*/

class DataCollector
{
public:
	DataCollector();

	void attach(std::shared_ptr<ILogger> observer);
	void detach(std::shared_ptr<ILogger> observer);
	void notify();
	void updateData();


	//data getters
	int getSpeed();
	int getRPM();
	int getEngTemp();
	int getGearNumber();
	int getFuelLevel();
	int getSteeringAngle();
	bool areLightsOn();
	bool isLeftBlinkerOn();
	bool isRightBlinkerOn();
	bool isHandBrakeOn();
	bool isOilWrong();
	bool isEngineDamaged();

	void setSpeedSensor(std::shared_ptr<SpeedSensor> sS);
	void setRPMSensor(std::shared_ptr<RPMSensor> rpmS);
	void setEngineTemperatureSensor(std::shared_ptr<EngineTemperatureSensor> etS);
	void setFuelLevelSensor(std::shared_ptr<FuelLevelSensor> flS);
	void setSteeringAngleSensor(std::shared_ptr<SteeringAngleSensor> saS);
	void setGearSensor(std::shared_ptr<GearSensor> gS);
	void setSmallerSensorsManager(std::shared_ptr<SmallerSensorsManager> ssM);


private:
	std::list<std::shared_ptr<ILogger>> loggers;


	//data
	int speed;
	int rpm;
	int engTemp;
	int gearNumber;
	int fuelLevel;
	int steeringAngle;
	std::bitset<6> flags;

	std::shared_ptr<SpeedSensor> speedSensor;
	std::shared_ptr<RPMSensor> rpmSensor;
	std::shared_ptr<EngineTemperatureSensor> engTempSensor;
	std::shared_ptr<FuelLevelSensor> fuelLevelSensor;
	std::shared_ptr<SteeringAngleSensor> steeringAngleSensor;
	std::shared_ptr<GearSensor> gearSensor;
	std::shared_ptr<SmallerSensorsManager> smallerSensors;
};

