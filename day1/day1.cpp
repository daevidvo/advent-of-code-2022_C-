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
	std::vector<int> maxes;

	for (int x = 0; x < v.size(); x += 1) {
		int sum = 0;

		for (int y = 0; y < v.at(x).size(); y += 1) {
			int num = std::stoi(v.at(x).at(y));

			sum += num;
		}
		
		maxes.push_back(sum);
		sum = 0;
	}

	// bubble sort
	for (int x = 0; x < maxes.size(); x += 1) {
		for (int y = 0; y < maxes.size(); y += 1) {
			if (maxes.at(y) > maxes.at(x)) {
				int temp = maxes.at(x);
				maxes.at(x) = maxes.at(y);
				maxes.at(y) = temp;
			}
		}
	}

	int sumMaxes = 0;

	for (int x = 0; x < 3; x += 1) {
		sumMaxes += maxes.at(maxes.size() - x - 1);
	}

	std::cout << "The total calories of the top three elves are: " << sumMaxes << std::endl;
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