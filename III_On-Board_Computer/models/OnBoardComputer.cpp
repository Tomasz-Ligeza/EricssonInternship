#include "OnBoardComputer.h"
#include "../loggers/SimpleLogger.h"
#include "../loggers/PrettyLogger.h"
#include "../sensors/Sensors.h"
#include <Windows.h>

OnBoardComputer::OnBoardComputer()
{
	dataCollector = std::make_shared<DataCollector>();

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

	//logger = std::make_shared<SimpleLogger>(dataCollector);
	logger = std::make_shared<PrettyLogger>(dataCollector);
	dataCollector->attach(logger);
}

void OnBoardComputer::run()
{
	while (true) {
		dataCollector->updateData();
		updateSensors();
		Sleep(1000);
	}
}

void OnBoardComputer::updateSensors()
{
	for (auto& sensor : sensors) {
		sensor->update();
	}
}