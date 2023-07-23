// AoC 2022 day 3: RuckSack Reorganization
// https://adventofcode.com/2022/day/3

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>

int main() {
	
	/*
	TODO: Find the sum of the properties of the duplicate item types in each rucksack

	Setup Parts;
	- Retrieve the data from data.txt
	- Hashmap for property values (a-z = 1-26 and A-Z =	27-52
	- Create an int variable for the sum of property values

	Approach:
	- Split the rucksacks into two halves (based on the length of the string)
	- Find the duplicate letter (case sensitive) in both halves
	- Find the value of the duplicate letter through the property value hashmap
	- sum+=value
	- std::cout << sum << std::endl;
	*/
		
	typedef std::unordered_map<std::string, int> hashmap;

	// setting up property values
	hashmap	letterValuesMap;

	std::string letters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

	for (int x = 0; x < letters.length(); x += 1) {
		std::string letter;
		letter = letters.at(x);

		letterValuesMap[letter] = x + 1;
	}
	
	// grabbing data 
	std::fstream data("./day3/data.txt");
	std::string	dataString;
	std::vector<std::string> dataVector;

	if (!data) {
		std::cout << "Unable to retrieve data" << std::endl;
		exit(1);
	}

	while (std::getline(data, dataString)) {
		dataVector.push_back(dataString);
	}


	/* === PART 1 === */
	for (int x = 0; x < dataVector.size(); x += 1) {
		std::string compartment1;
		std::string compartment2;
		
		std::string element = dataVector.at(x);
		
		// splicing strings into their respective halves
		compartment1 = element.substr(0, element.length() / 2);
		compartment2 = element.substr(element.length() / 2, element.length() / 2);

		

	}

	


	return 0;
}