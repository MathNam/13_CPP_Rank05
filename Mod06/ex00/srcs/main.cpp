#include "ScalarConverter.hpp"
#include <iostream>

int	main(int ac, char ** av)
{
	if (ac != 2) {
		std::cout << "Usage: ./convert_scalar <scalar_to_convert>\n"
			"Valid scalars to convert: int, float, double or char."
			<< std::endl;
		return (1);
	}
	
	try {
		std::cout << "---- Converting [" << av[1] << "]" << std::endl;
		ScalarConverter	scalarConverter(av[1]);
		std::cout << scalarConverter << std::endl;
	}
	catch(const std::exception& e) {
		std::cout << "Input could not be converted: " << e.what() << std::endl;
	}
	return (0);
}
