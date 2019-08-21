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
	std::cout << std::boolalpha << testString.startsWith("option 1") << std::endl;
	std::cout << std::boolalpha << testString.endsWith("option 2") << std::endl;
}

void dateExample() {
	abstractcpp::Date date = abstractcpp::Date("January 1 2000 00:00:00");
	abstractcpp::Date date2 = abstractcpp::Date(1);
	abstractcpp::Date now = abstractcpp::Date::now();

	std::cout << date.getTime() << std::endl;
	std::cout << date2.getFullYear() << std::endl;
	std::cout << now.getDateString() << std::endl;
}

int main() {
	stringExample();
	dateExample();

	std::cin.get();
	return 0;
}