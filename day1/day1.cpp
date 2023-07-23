// AoC 2022 day 1: Calorie Counting
// https://adventofcode.com/2022/day/1

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

void findMax(std::vector<std::vector<std::string>> const& v) {
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

	std::cout << "The highest amount of calories carried by an elf is: " << max << std::endl;
}

void findTopThreeMax(std::vector<std::vector<std::string>> const& v) {
	// YIKES THIS IS MESSY LMAO
	int max1 = 0;
	int max2 = 0;
	int max3 = 0;

	for (int x = 0; x < v.size(); x += 1) {
		int sum = 0;

		for (int y = 0; y < v.at(x).size(); y += 1) {
			int num = std::stoi(v.at(x).at(y));

			sum += num;
		}

		if (sum > max1) {
			max3 = max2;
			max2 = max1;
			max1 = sum;
		}
		else if (sum > max2) {
			max3 = max2;
			max2 = sum;
		}
		else if (sum > max3) {
			max3 = sum;
		}
	}

	std::cout << max1 + max2 + max3 << std::endl;

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

	/*
	================================ PART 1 ================================ 
	*/

	findMax(v);

	/*
	================================ PART 2 ================================ 
	*/

	findTopThreeMax(v);

	return 0;
}