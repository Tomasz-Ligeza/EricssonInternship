#include <iostream>
#include <algorithm>

long pow(int exp, int fou = 2) {
	long val{ 1 };
	while (exp-- > 0) {
		val *= fou;
	}
	return val;
}

int binToDec(std::string binary) {
	int exponent = binary.size() - 1;
	int decimal { 0 };
	for (auto& digit : binary) {
		if (digit == '1')
			decimal += pow(exponent);
		exponent--;
	}
	return decimal;
}

std::string decToBin(int decimal) {
	std::string binary;
	while (decimal > 0) {
		binary += '0' + decimal % 2;
		decimal /= 2;
	}
	std::reverse(binary.begin(), binary.end());
	return binary;
}

int main() {
	do {
		char option {' '};
		std::cout << "Select operation: \n"
			<< "-> [1] conversion from binary to decimal\n"
			<< "-> [2] conversion from decimal to binary\n"
			<< "-> [*] exit\n";
		std::cin >> option;
		switch (option) {
		case '1': {
			system("cls");
			std::cout << "Please enter binary number: ";
			std::string binary;
			std::cin >> binary;
			std::cout << "\n" << binary << " [BIN] = " << binToDec(binary) << " [DEC]\n";
			break;
		}
		case '2': {
			system("cls");
			std::cout << "Please enter decimal number: ";
			int decimal;
			std::cin >> decimal;
			std::cout << "\n" << decimal << " [DEC] = " << decToBin(decimal) << " [BIN]\n";
			break;
		}
		default: {
			return 0;
		}
		}
		std::cout << "Once more? [y/n] ";
		std::cin >> option;
		if (option == 'n')
			break;
		else
			system("cls");
	} while (true);
	
	return 0;
}