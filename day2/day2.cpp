// AoC 2022 day 2: Rock Paper Scissors
// https://adventofcode.com/2022/day/2

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>

void calcTotal(std::vector<std::string> const& dataVector, std::unordered_map<std::string, int> const& map) {
	int total = 0;
	int roundPoints;

	for (int x = 0; x < dataVector.size(); x += 1) {
		roundPoints = map.at(dataVector.at(x));
		total += roundPoints;
	}

	std::cout << total << std::endl;
}

int main() {
	// setting up problem
	// adding the data into a vector
	std::fstream data("./day2/data.txt");
	std::string dataString;
	std::vector<std::string> dataVector;

	if (!data) {
		std::cout << "Unable to retrieve data" << std::endl;
		exit(1);
	}

	while (std::getline(data, dataString)) {
		if (dataString.length() != 0) {
			dataVector.push_back(dataString);
		}
	}

	typedef std::unordered_map<std::string, int> hashMap;
	
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
	hashMap hashMapPart1;

	hashMapPart1["A X"] = 4;
	hashMapPart1["A Y"] = 8;
	hashMapPart1["A Z"] = 3;
	hashMapPart1["B X"] = 1;
	hashMapPart1["B Y"] = 5;
	hashMapPart1["B Z"] = 9;
	hashMapPart1["C X"] = 7;
	hashMapPart1["C Y"] = 2;
	hashMapPart1["C Z"] = 6;

	calcTotal(dataVector, hashMapPart1);

	/* === PART 2 === */
	
	// same thing except:
	// X = need to lose
	// Y = need to tie
	// Z = need to win
	hashMap hashMapPart2;

	hashMapPart2["A X"] = 3;
	hashMapPart2["A Y"] = 4;
	hashMapPart2["A Z"] = 8;
	hashMapPart2["B X"] = 1;
	hashMapPart2["B Y"] = 5;
	hashMapPart2["B Z"] = 9;
	hashMapPart2["C X"] = 2;
	hashMapPart2["C Y"] = 6;
	hashMapPart2["C Z"] = 7;

	calcTotal(dataVector, hashMapPart2);

	return 0;
}