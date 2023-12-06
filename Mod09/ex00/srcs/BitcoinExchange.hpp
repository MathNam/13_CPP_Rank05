#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <cstdlib>
#include <exception>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <cctype>
#include <stddef.h>
#include <sstream>
#include <string>

class BitcoinExchange {
public:
	BitcoinExchange();
	BitcoinExchange(BitcoinExchange const & cpy);
	BitcoinExchange& operator=(BitcoinExchange const & rhs); 
	~BitcoinExchange();

	void	fillData(std::string dataFile);
	double	findPrice(std::string const & date);
	void 	processFile(char* inputFileName);

private:
	class invalidFormat : public std::exception {
		public:
			virtual const char* what(void) const throw();
	};
	class invalidDate : public std::exception {
		public:
			virtual const char* what(void) const throw();
	};
	class qtyNegative : public std::exception {
		public:
			virtual const char* what(void) const throw();
	};
	class qtyTooLarge : public std::exception {
		public:
			virtual const char* what(void) const throw();
	};
	class dataFileCorrupted : public std::exception {
		public:
			virtual const char* what(void) const throw();
	};

	std::map<std::string, double> _btcPrices;
};

#endif
