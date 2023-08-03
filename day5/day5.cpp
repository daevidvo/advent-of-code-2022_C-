#include <iostream>
#include <fstream>
#include <stack>
#include <string>
#include <vector>


int main() {
	std::string dataString;
	std::fstream data("./day5/data.txt");
	std::vector<std::string> dataVector;

	if (!data) {
		std::cout << "Unable to retrieve data" << std::endl;

		exit(1);
	}

	while (std::getline(data, dataString)) {
		dataVector.push_back(dataString);
	}

	std::stack<char> stack1;
	std::stack<char> stack2;
	std::stack<char> stack3;
	std::stack<char> stack4;
	std::stack<char> stack5;
	std::stack<char> stack6;
	std::stack<char> stack7;
	std::stack<char> stack8;
	std::stack<char> stack9;

	std::vector<std::stack<char>> stackVector;

	stackVector.push_back(stack1);
	stackVector.push_back(stack2);
	stackVector.push_back(stack3);
	stackVector.push_back(stack4);
	stackVector.push_back(stack5);
	stackVector.push_back(stack6);
	stackVector.push_back(stack7);
	stackVector.push_back(stack8);
	stackVector.push_back(stack9);

	int indexNum = 1;
	int counter = 0;
	while (counter < 9) {
		int rowNum = 7;
		for (int x = 0; x < 8; x += 1) {
			if (dataVector.at(rowNum).at(indexNum) != ' ') {
				stackVector.at(counter).push(dataVector.at(rowNum).at(indexNum));
			}
			
			rowNum -= 1;
		}
	
		indexNum += 4;
		counter += 1;
	}

	std::cout << stackVector.at(0).top() << "\n";

	return 0;
}