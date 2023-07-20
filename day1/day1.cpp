// AoC 2022 day 1: Calorie Counting
// https://adventofcode.com/2022/day/1

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
// for typeid to work
#include <typeinfo>

void printVector(std::vector<std::vector<std::string>> const& v) {
	int sum = 0;
	int max = 0;

	for (int x = 0; x < v.size(); x += 1) {
		for (int y = 0; y < v.at(x).size(); y += 1) {
			int num = std::stoi(v.at(x).at(y));
			sum += num;
		}
		
		if (sum > max) {
			max = sum;
		}
		sum = 0;
	}

	std::cout << max << std::endl;
}

bool stringToBool(std::string const& s) {
	return (bool)std::stoi(s);
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
	std::vector<std::vector<std::string>> v;

	while (std::getline(data, dataString)) {
		if (dataString.length() == 0) {
			v.push_back(dataVector);
			dataVector.clear();
		}
		else {
			dataVector.push_back(dataString);
		}
	}
	
	printVector(v);

	return 0;
}