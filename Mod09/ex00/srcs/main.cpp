#include "BitcoinExchange.hpp"

int	main(int ac, char *av[])
{
	if (ac != 2) {
		std::cout << "Invalid number of arguments:\n [Usage] : ./btc [filename]" << std::endl;
		return 1;
	}
	BitcoinExchange btc;
	std::string	dataFileName = "data/data.csv";
	try {
		btc.fillData(dataFileName);
		btc.processFile(av[1]);
	}
	catch (std::exception & e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
	return 0;
}
