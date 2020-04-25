#include "abstractcpp/arrays.hpp"
#include <vector>

namespace abstractcpp
{
	template<typename T>
	std::string internal_to_string(const std::vector<T>& arr)
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
	
	std::string arrays::to_string(const std::vector<int>& arr)
	{
		return internal_to_string<int>(arr);
	}

	std::string arrays::to_string(const std::vector<unsigned int>& arr)
	{
		return internal_to_string<unsigned int>(arr);
	}

	std::string arrays::to_string(const std::vector<long>& arr)
	{
		return internal_to_string<long>(arr);
	}

	std::string arrays::to_string(const std::vector<unsigned long>& arr)
	{
		return internal_to_string<unsigned long>(arr);
	}

	std::string arrays::to_string(const std::vector<long long>& arr)
	{
		return internal_to_string<long long>(arr);
	}

	std::string arrays::to_string(const std::vector<unsigned long long>& arr)
	{
		return internal_to_string<unsigned long long>(arr);
	}

	std::string arrays::to_string(const std::vector<float>& arr)
	{
		return internal_to_string<float>(arr);
	}

	std::string arrays::to_string(const std::vector<double>& arr)
	{
		return internal_to_string<double>(arr);
	}

	std::string arrays::to_string(const std::vector<long double>& arr)
	{
		return internal_to_string<long double>(arr);
	}

	template<typename T>
	std::string internal_deep_to_string(const std::vector< std::vector<T> >& arr)
	{
		std::string stringified_array = "[";
		for (int i = 0; i < arr.size(); i++)
		{
			stringified_array += internal_to_string<T>(arr[i]);
			if (i + 1 < arr.size()) stringified_array += ", ";
		}
		stringified_array += "]";
		return stringified_array;
	}

	std::string arrays::deep_to_string(const std::vector< std::vector<int> >& arr)
	{
		return internal_deep_to_string<int>(arr);
	}

	std::string arrays::deep_to_string(const std::vector< std::vector<unsigned int> >& arr)
	{
		return internal_deep_to_string<unsigned int>(arr);
	}

	std::string arrays::deep_to_string(const std::vector< std::vector<long> >& arr)
	{
		return internal_deep_to_string<long>(arr);
	}

	std::string arrays::deep_to_string(const std::vector< std::vector<unsigned long> >& arr)
	{
		return internal_deep_to_string<unsigned long>(arr);
	}

	std::string arrays::deep_to_string(const std::vector< std::vector<long long> >& arr)
	{
		return internal_deep_to_string<long long>(arr);
	}

	std::string arrays::deep_to_string(const std::vector< std::vector<unsigned long long> >& arr)
	{
		return internal_deep_to_string<unsigned long long>(arr);
	}

	std::string arrays::deep_to_string(const std::vector< std::vector<float> >& arr)
	{
		return internal_deep_to_string<float>(arr);
	}

	std::string arrays::deep_to_string(const std::vector< std::vector<double> >& arr)
	{
		return internal_deep_to_string<double>(arr);
	}

	std::string arrays::deep_to_string(const std::vector< std::vector<long double> >& arr)
	{
		return internal_deep_to_string<long double>(arr);
	}
}
