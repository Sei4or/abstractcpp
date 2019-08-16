#include "AbstractCPP.hpp"
#include "exceptions.hpp"

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <chrono>
#include <sstream>

namespace abstractcpp {
	// STRING CLASS
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

	bool string::startsWith(std::string comparator)
	{
		std::string::size_type comparatorPosition = internalString.find(comparator);
		return comparatorPosition != std::string::npos && comparatorPosition == 0;
	}

	bool string::endsWith(std::string comparator)
	{
		std::string::size_type comparatorPosition = internalString.find_last_of(comparator);
		return comparatorPosition != std::string::npos && comparatorPosition == internalString.size() - 1;
	}

	// DATE CLASS
	Date::Date(long long value)
	{
		std::chrono::milliseconds duration(value);
		timepoint = std::chrono::time_point<std::chrono::system_clock>(duration);
		timeStructure = getTimeStructure(timepoint);
	}

	Date::Date(std::string dateString)
	{
		std::tm timeStructure = {};
		std::stringstream ss(dateString);
		ss >> std::get_time(&timeStructure, "%b %d %Y %H:%M:%S");
		timepoint = std::chrono::system_clock::from_time_t(std::mktime(&timeStructure));
		timeStructure = getTimeStructure(timepoint);
	}

	// I will forever hate this
	Date::Date(std::chrono::time_point<std::chrono::system_clock> tp)
	{
		timepoint = tp;
		timeStructure = getTimeStructure(timepoint);
	}

	tm Date::getTimeStructure(std::chrono::time_point<std::chrono::system_clock> timepoint)
	{
		std::time_t t = std::chrono::system_clock::to_time_t(timepoint);
		struct tm tm;
		::localtime_s(&tm, &t);
		return tm;
	}

	Date Date::now()
	{
		return Date(std::chrono::system_clock::now());
	}

	// Seemingly unstable method (Use at your own caution)
	std::string Date::getDateString()
	{
		char buffer[80];
		strftime(buffer, 80, "%c", &timeStructure);

		return buffer;
	}

	long long Date::getTime()
	{
		return std::chrono::time_point_cast<std::chrono::milliseconds>(timepoint).time_since_epoch().count();
	}

	int Date::getDate()
	{
		return timeStructure.tm_mday;
	}

	int Date::getDay()
	{
		return timeStructure.tm_wday;
	}

	int Date::getFullYear()
	{
		return timeStructure.tm_year + 1900;
	}

	int Date::getHours()
	{
		return timeStructure.tm_hour;
	}

	int Date::getMilliseconds()
	{
		return timeStructure.tm_sec * 1000;
	}

	int Date::getMinutes()
	{
		return timeStructure.tm_min;
	}

	int Date::getMonth()
	{
		return timeStructure.tm_mon;
	}

	int Date::getSeconds()
	{
		return timeStructure.tm_sec;
	}

	bool Date::isDaylightSavings()
	{
		if (timeStructure.tm_isdst < 0) return NULL;
		return timeStructure.tm_isdst > 0;
	}
}