#include <iostream>
#include "./models/OnBoardComputer.h"


/*
	There is some unpractical code in main, but it is created just to give
	user opportunity to choose frequency and type of logger.

	There is no input verification, because this program
	is written to present OOP convention and some design patterns.

	Sensors classes job is to just serve any data, so their "algorithms" are poor.
	They just imitate real sensors work.
*/


int main() {
	OnBoardComputer* onBoardComputer = nullptr;
	do {
		char logger;
		std::cout << "Choose type of logger:\n"
			<< "[s] simple\n"
			<< "[p] pretty\n";
		std::cin >> logger;
		int period = 0;
		std::cout << "Write period of time (seconds) between logs: ";
		std::cin >> period;
		if (logger == 's')
			onBoardComputer = new OnBoardComputer(LoggerType::SIMPLE, period);
		if (logger == 'p')
			onBoardComputer = new OnBoardComputer(LoggerType::PRETTY, period);
	} while (onBoardComputer == nullptr);
	onBoardComputer->run();
	return 0;
}