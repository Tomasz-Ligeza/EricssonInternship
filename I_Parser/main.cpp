#include <iostream>
#include <list>
#include <bitset>
#include <fstream>

/*
	This problem is very easy, so solved it without OOP style,
	mainly becouse it`s an "algorithmic" problem.

	I`m using std::bitset, because keeping every correct "protocol"
	as std::string would take much more memory.

	I`m only counting incorrect protocols, because I don`t use them later.
*/

int main() {
	std::list<std::bitset<8>> correct;
	unsigned int incorrect { 0 };

	std::ifstream input("input.txt");
	if (input.good()) {
		while (!input.eof()) {
			std::string asStringProtocol;
			input >> asStringProtocol;
			std::bitset<8> protocol(asStringProtocol);
			if (protocol[4] == protocol[0] && protocol.count() != 0)
				correct.push_back(protocol);
			else
				incorrect++;
		}
		input.close();

		std::ofstream output("output.txt");
		output << correct.size() + incorrect << "\n"
			<< incorrect << "\n";
		for (auto& protocol : correct) {
			output << protocol << " ";
		}
		output.close();
	}

	return 0;
}