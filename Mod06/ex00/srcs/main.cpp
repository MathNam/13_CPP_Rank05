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
	
	std::cout << "---- Converting [" << av[1] << "]" << std::endl;
	ScalarConverter::convert(av[1]);

	return (0);
}
