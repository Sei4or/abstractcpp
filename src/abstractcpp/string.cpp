#include "abstractcpp/string.hpp"

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
		return internalString.find(searchString) != std::string::npos;
	}

	bool string::starts_with(std::string comparator)
	{
		std::string::size_type comparatorPosition = internalString.find(comparator);
		return comparatorPosition != std::string::npos && comparatorPosition == 0;
	}

	bool string::ends_with(std::string comparator)
	{
		std::string::size_type comparatorPosition = internalString.find_last_of(comparator);
		return comparatorPosition != std::string::npos && comparatorPosition == internalString.size() - 1;
	}
}