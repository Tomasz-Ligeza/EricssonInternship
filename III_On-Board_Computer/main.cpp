#include <iostream>
#include "./models/OnBoardComputer.h"


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
			onBoardComputer = new OnBoardComputer(SIMPLE, period);
		if (logger == 'p')
			onBoardComputer = new OnBoardComputer(PRETTY, period);
	} while (onBoardComputer == nullptr);
	onBoardComputer->run();
	return 0;
}