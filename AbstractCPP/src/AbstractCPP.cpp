#include "AbstractCPP.h"

#include <iostream>
#include <string>
#include <vector>

namespace abstractcpp {
	std::vector<std::string> splitString(std::string string, const char* splitter) {
		std::vector<std::string> stringVector;
		std::string currentString;
		for (int i = 0; i < string.length(); i++) {
			char currentChar = string.at(i);
			if (currentChar == *splitter) {
				stringVector.push_back(currentString);
				currentString = "";

				if (string.substr(i + 1, string.size()).find_first_not_of(" ") == std::string::npos)
					return stringVector;

				i++;
			}
			else {
				currentString += currentChar;
			}
		}
		stringVector.push_back(currentString);
		return stringVector;
	}
}