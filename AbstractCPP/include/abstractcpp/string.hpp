#pragma once

#include <string>
#include <vector>

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
}