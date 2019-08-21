#include "abstractcpp/date.hpp"

#include <iomanip>
#include <sstream>

namespace abstractcpp {
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