#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <cstdlib>
#include <ctime>
#include <exception>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <cctype>
#include <sstream>
#include <stdexcept>
#include <string>
#include <strings.h>
#include <sys/stat.h>

class BitcoinExchange {
public:
	BitcoinExchange();
	BitcoinExchange(BitcoinExchange const & cpy);
	BitcoinExchange& operator=(BitcointExchange const & rhs); 
	~BitcoinExchange();

	void	fillData(std::string dataFile);
	void	processFile(std::string dataFile);
private:
	class invalidFormat : public std::exception {
		public:
			virtual const char* what(void) const throw();
	}
	class invalidDateFormat : public std::exception {
		public:
			virtual const char* what(void) const throw();
	}
	class invalidValue : public std::exception {
		public:
			virtual const char* what(void) const throw();
	}

	std::map _btcPrices<std::string, double>;

	void	lineFormatError();
}

#endif
