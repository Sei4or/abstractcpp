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

		static tm get_time_structure(std::chrono::time_point<std::chrono::system_clock> timepoint);
		static Date now();

		std::string get_date_string();
		long long get_time();
		int get_date();
		int get_day();
		int get_full_year();
		int get_hours();
		int get_milliseconds();
		int get_minutes();
		int get_month();
		int get_seconds();
		bool is_daylight_savings();
	};
}