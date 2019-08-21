#pragma once

#include <string>
#include <chrono>

namespace abstractcpp {
	class Date
	{
	private:
		std::chrono::time_point<std::chrono::system_clock> timepoint;
		tm timeStructure;

	public:
		Date(long long value);
		Date(std::string dateString);
		Date(std::chrono::time_point<std::chrono::system_clock> tp);

		static tm getTimeStructure(std::chrono::time_point<std::chrono::system_clock> timepoint);
		static Date now();

		std::string getDateString();
		long long getTime();
		int getDate();
		int getDay();
		int getFullYear();
		int getHours();
		int getMilliseconds();
		int getMinutes();
		int getMonth();
		int getSeconds();
		bool isDaylightSavings();
	};
}