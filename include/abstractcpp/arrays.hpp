#pragma once
#include <string>
#include <vector>

namespace abstractcpp
{
	class arrays
	{
	public:
		static std::string to_string(const std::vector<int>& arr);
		static std::string to_string(const std::vector<unsigned int>& arr);
		static std::string to_string(const std::vector<long>& arr);
		static std::string to_string(const std::vector<unsigned long>& arr);
		static std::string to_string(const std::vector<long long>& arr);
		static std::string to_string(const std::vector<unsigned long long>& arr);
		static std::string to_string(const std::vector<float>& arr);
		static std::string to_string(const std::vector<double>& arr);
		static std::string to_string(const std::vector<long double>& arr);
		static std::string deep_to_string(const std::vector< std::vector<int> >& arr);
		static std::string deep_to_string(const std::vector< std::vector<unsigned int> >& arr);
		static std::string deep_to_string(const std::vector< std::vector<long> >& arr);
		static std::string deep_to_string(const std::vector< std::vector<unsigned long> >& arr);
		static std::string deep_to_string(const std::vector< std::vector<long long> >& arr);
		static std::string deep_to_string(const std::vector< std::vector<unsigned long long> >& arr);
		static std::string deep_to_string(const std::vector< std::vector<float> >& arr);
		static std::string deep_to_string(const std::vector< std::vector<double> >& arr);
		static std::string deep_to_string(const std::vector< std::vector<long double> >& arr);
	};
}
