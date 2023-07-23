// AoC 2022 day 2: Rock Paper Scissors
// https://adventofcode.com/2022/day/2

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>

int main() {
	// adding the data into a vector
	std::fstream data("./day2/data.txt");
	std::string dataString;
	std::vector<std::string> dataVector;

	while (std::getline(data, dataString)) {
		if (dataString.length() != 0) {
			dataVector.push_back(dataString);
		}
	}
	
	/* === PART 1 === */

	// setting up hash map for win/loss/tie condiitons
	// A, X = rock
	// B, Y = paper
	// C, Z = scissors
	// rock = 1 point
	// papers = 2 points
	// scissors = 3 points
	// loss = 0 points
	// tie = 3 points
	// win = 6 points 
	std::unordered_map<std::string, int> hashMap;

	hashMap["A X"] = 4;
	hashMap["A Y"] = 8;
	hashMap["A Z"] = 3;
	hashMap["B X"] = 1;
	hashMap["B Y"] = 5;
	hashMap["B Z"] = 9;
	hashMap["C X"] = 7;
	hashMap["C Y"] = 2;
	hashMap["C Z"] = 6;

	int total = 0;
	int roundPoints;

	for (int x = 0; x < dataVector.size(); x += 1) {
		roundPoints = hashMap[dataVector.at(x)];
		total += roundPoints;
	}

	std::cout << total << std::endl;

	return 0;
}