// AoC 2022 day 4: Camp Cleanup
// https://www.adventofcode/2022/day/4

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

std::string spliceString(std::string str, int num) {
	int commaIndex = str.find(",");

	std::string subString; 
	
	if (num == 0) {
		subString = str.substr(0, commaIndex);

		return subString;
	}
	
	if (num == 1) {
		// adding 1 to remove the command and space at the beginning of the second pair
		commaIndex += 1;
		subString = str.substr(commaIndex, str.size());

		return subString; 
	}
}

int stringToNum(std::string str, int num) {
	int dashIndex = str.find("-");

	int returnNum;

	if (num == 0) {
		returnNum = std::stoi(str.substr(0, dashIndex));

		return returnNum;
	}

	if (num == 1) {
		// adding 1 to remove the dash
		dashIndex += 1;
		returnNum = std::stoi(str.substr(dashIndex, str.size()));

		return returnNum;
	}
}

int main() {
	std::fstream data("./day4/data.txt");
	std::string dataString;

	if (!data) {
		std::cout << "Unable to load data" << std::endl;
		exit(1);
	}

	std::vector<std::string> dataVector;

	while (std::getline(data, dataString)) {
		dataVector.push_back(dataString);
	}

	/* === PART 1 === */
	
	int pairCounter = 0;

	for (int x = 0; x < dataVector.size(); x += 1) {
		std::string num1String = spliceString(dataVector.at(x), 0);
		std::string num2String = spliceString(dataVector.at(x), 1);

		int firstPairFirstNum = stringToNum(num1String, 0);
		int firstPairSecondNum = stringToNum(num1String, 1);
		int secondPairFirstNum = stringToNum(num2String, 0);
		int secondPairSecondNum = stringToNum(num2String, 1);
		
		if ((firstPairFirstNum >= secondPairFirstNum) && (firstPairSecondNum <= secondPairSecondNum)) {
			pairCounter += 1;
		}
		else if ((secondPairFirstNum >= firstPairFirstNum) && (secondPairSecondNum <= firstPairSecondNum)) {
			pairCounter += 1;
		}
	}

	std::cout << pairCounter << std::endl;

	/* === PART 2 === */

	pairCounter = 0;

	for (int x = 0; x < dataVector.size(); x += 1) {
		std::string num1String = spliceString(dataVector.at(x), 0);
		std::string num2String = spliceString(dataVector.at(x), 1);

		int firstPairFirstNum = stringToNum(num1String, 0);
		int firstPairSecondNum = stringToNum(num1String, 1);
		int secondPairFirstNum = stringToNum(num2String, 0);
		int secondPairSecondNum = stringToNum(num2String, 1);
		
		if ((firstPairSecondNum >= secondPairFirstNum) && (firstPairFirstNum <= secondPairSecondNum)) {
			pairCounter += 1;
		}
		else if ((firstPairFirstNum <= secondPairSecondNum) && (secondPairFirstNum <= firstPairSecondNum)) {
			pairCounter += 1;
		}
	}

	std::cout << pairCounter << std::endl;

	return 0;
}