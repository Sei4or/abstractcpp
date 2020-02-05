#include "abstractcpp/arrays.hpp"
#include <vector>

namespace abstractcpp
{
	std::string arrays::to_string(const std::vector<int>& arr)
	{
		std::string stringified_array = "[";
		for (int i = 0; i < arr.size(); i++)
		{
			stringified_array += std::to_string(arr[i]);
			if (i + 1 < arr.size()) stringified_array += ", ";
		}
		stringified_array += "]";
		return stringified_array;
	}

	std::string arrays::deep_to_string(const std::vector< std::vector<int> >& arr)
	{
		std::string stringified_array = "[";
		for (int i = 0; i < arr.size(); i++)
		{
			stringified_array += to_string(arr[i]);
			if (i + 1 < arr.size()) stringified_array += ", ";
		}
		stringified_array += "]";
		return stringified_array;
	}
}
