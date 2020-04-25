#include "AbstractCPP.hpp"

#include <iostream>

void stringExample() {
	abstractcpp::string testString = abstractcpp::string("option 1, option 2");

	std::vector<std::string> vectorString = testString.split(",");
	std::cout << "String options" << std::endl;
	for (std::vector<std::string>::const_iterator i = vectorString.begin(); i != vectorString.end(); i++) { // yes I could use the iterator, but this was for testing
		std::cout << *i << std::endl;
	}

	std::cout << std::boolalpha << testString.contains("2") << std::endl;
	std::cout << std::boolalpha << testString.starts_with("option 1") << std::endl;
	std::cout << std::boolalpha << testString.ends_with("option 2") << std::endl;
}

void dateExample() {
	abstractcpp::Date date = abstractcpp::Date("January 1 2000 00:00:00");
	abstractcpp::Date date2 = abstractcpp::Date(1);
	abstractcpp::Date now = abstractcpp::Date::now();

	std::cout << date.get_time() << std::endl;
	std::cout << date2.get_full_year() << std::endl;
	std::cout << now.get_date_string() << std::endl;
}

void arrayExample()
{
	std::vector<int> intArray = { 1, 2, 3 };
	std::cout << abstractcpp::arrays::to_string(intArray) << std::endl;
	std::vector<std::vector<int>> twoDArray = { {1, 2, 3}, {11, 4444, 222} };
	std::cout << abstractcpp::arrays::deep_to_string(twoDArray) << std::endl;
}

int main() {
	stringExample();
	dateExample();
	arrayExample();

	std::cin.get();
	return 0;
}