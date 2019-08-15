#pragma once

#include <string>
#include <vector>
#include <chrono>

namespace abstractcpp {
	class string
	{
	private:
		std::string internalString;

	public:
		string(std::string initialString);

		std::vector<std::string> split(const char* splitter);
		bool contains(std::string searchString);
		bool startsWith(std::string comparator);
		bool endsWith(std::string comparator);

		std::string str() { return internalString; }
	};

	class Date
	{
	private:
		std::chrono::time_point<std::chrono::system_clock> timepoint;

	public:
		Date(long long value);
		Date(std::string dateString);
		Date(std::chrono::time_point<std::chrono::system_clock> tp);

		static Date now();

		std::string getDateString();
		long long getTime();
	};
}