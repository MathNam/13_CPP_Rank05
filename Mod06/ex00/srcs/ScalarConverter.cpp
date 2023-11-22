#include "ScalarConverter.hpp"

#define	PRINT_MSG 0

std::numeric_limits<int>::max();
std::numeric_limits<int>::min();
std::numeric_limits<float>::max();
std::numeric_limits<float>::min();
std::numeric_limits<char>::max();
std::numeric_limits<char>::min();

ScalarConverter::ScalarConverter(void)
{
	std::cout << "ScalarConverter default constructor called." << std::endl;
}

ScalarConverter::ScalarConverter(ScalarConverter const &src)
{
		std::cout << "ScalarConverter copy constructor called." << std::endl;
}

ScalarConverter::~ScalarConverter(void)
{
		std::cout << "ScalarConverter destructor called." << std::endl;
}

static 

void	ScalarConverter::convert(std::string const & str)
{
	
}
