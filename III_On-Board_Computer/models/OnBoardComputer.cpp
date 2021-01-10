#include "OnBoardComputer.h"
#include "../loggers/SimpleLogger.h"
#include "../loggers/PrettyLogger.h"
#include "../sensors/Sensors.h"
#include <chrono>

OnBoardComputer::OnBoardComputer(LoggerType loggerType, int period)
{
	this->period = period;
	this->refreshSensorsPeriod = 113;
	dataCollector = std::make_shared<DataCollector>();
	if(loggerType == LoggerType::SIMPLE)
		logger = std::make_shared<SimpleLogger>(dataCollector);
	else
		logger = std::make_shared<PrettyLogger>(dataCollector);
	
	initializeSensors();
	dataCollector->attach(logger);
}

void OnBoardComputer::run()
{
	auto previousDataUpdate = std::chrono::steady_clock::now();
	auto previousSensorsRefresh = std::chrono::steady_clock::now();

	while (true) {
		if(std::chrono::duration_cast<std::chrono::seconds>(std::chrono::steady_clock::now() - previousDataUpdate).count() >= period) {
			dataCollector->updateData();
			previousDataUpdate = std::chrono::steady_clock::now();
		}
		if (std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - previousSensorsRefresh).count() >= refreshSensorsPeriod) {
			updateSensors();
			previousSensorsRefresh = std::chrono::steady_clock::now();
		}
	}
}

void OnBoardComputer::initializeSensors()
{
	std::shared_ptr<SpeedSensor> sS = std::make_shared<SpeedSensor>();
	sensors.push_back(sS);
	dataCollector->setSpeedSensor(sS);

	std::shared_ptr<RPMSensor> rS = std::make_shared<RPMSensor>();
	sensors.push_back(rS);
	dataCollector->setRPMSensor(rS);

	std::shared_ptr<EngineTemperatureSensor> eS = std::make_shared<EngineTemperatureSensor>();
	sensors.push_back(eS);
	dataCollector->setEngineTemperatureSensor(eS);

	std::shared_ptr<GearSensor> gS = std::make_shared<GearSensor>();
	sensors.push_back(gS);
	dataCollector->setGearSensor(gS);

	std::shared_ptr<FuelLevelSensor> fS = std::make_shared<FuelLevelSensor>();
	sensors.push_back(fS);
	dataCollector->setFuelLevelSensor(fS);

	std::shared_ptr<SteeringAngleSensor> saS = std::make_shared<SteeringAngleSensor>();
	sensors.push_back(saS);
	dataCollector->setSteeringAngleSensor(saS);

	std::shared_ptr<SmallerSensorsManager> sM = std::make_shared<SmallerSensorsManager>();
	sensors.push_back(sM);
	dataCollector->setSmallerSensorsManager(sM);
}

void OnBoardComputer::updateSensors()
{
	for (auto& sensor : sensors) {
		sensor->update();
	}
}