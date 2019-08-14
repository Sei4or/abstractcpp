#include "AbstractCPP.hpp"
#include "exceptions.hpp"

#include <iostream>
#include <string>
#include <vector>

namespace abstractcpp {
	string::string(std::string initialString) {
		internalString = initialString;
	}

	std::vector<std::string> string::split(const char* splitter)
	{
		std::string tempString = str();
		std::vector<std::string> stringVector;
		std::string currentString;
		for (int i = 0; i < tempString.length(); i++) {
			char currentChar = tempString.at(i);
			if (currentChar == *splitter) {
				stringVector.push_back(currentString);
				currentString = "";

				if (tempString.substr(i + 1, tempString.size()).find_first_not_of(" ") == std::string::npos)
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

	bool string::contains(std::string searchString)
	{
		throw NotImplementedException();
	}
}