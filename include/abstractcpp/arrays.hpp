#pragma once
#include <string>
#include <vector>

namespace abstractcpp
{
	class arrays
	{
	public:
		static std::string to_string(const std::vector<int>& arr);
		static std::string deep_to_string(const std::vector< std::vector<int> >& arr);
	};
}
