// AoC 2022 day 1: Calorie Counting
// https://adventofcode.com/2022/day/1

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

void printVector(std::vector<std::string> const& dataVector) {
	for (int x = 0; x < dataVector.size(); x += 1) {
		std::cout << dataVector.at(x) << "\n";
	}
}

bool stringToBool(std::string const& s) {
	bool b = 

	std::istringstream(s) >> b;
}

int main() {
	// reading data
	// file is executing from .sln so that's why we do ./day1/data.txt
	std::ifstream data("./day1/data.txt");
	std::string dataString;

	if (!data) {
		std::cout << "Unable to open file\n";
		exit(1);
	}

	std::vector<std::string> dataVector;

	while (std::getline(data, dataString)) {
		if (stringToBool(dataString)) {
			dataVector.push_back(dataString);
		}
	}
	
	printVector(dataVector);

	return 0;
}