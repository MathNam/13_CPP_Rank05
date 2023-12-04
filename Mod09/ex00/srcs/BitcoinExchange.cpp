#include "BitcoinExchange.hpp"

//Contructors and destructors
BitcoinExchange::BitcoinExchange() {
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const & cpy) {
	*this = cpy;
}

BitcoinExchange& BitcoinExchange::operator=(BitcoinExchange const & rhs) {
	if (this != &rhs)
		_btcPrices = rhs._btcPrices;
	return *this;
}

BitcoinExchange::~BitcoinExchange() {
}

//Exeception definitions
const char* BitcoinExchange::invalidFormat::what(void) const throw() {
	return "Invalid format";
}

const char* BitcoinExchange::invalidDate::what(void) const throw() {
	return "Invalid date";
}

const char* BitcoinExchange::invalidValueNegative::what(void) const throw() {
	return "not a positive number";
}

const char* BitcoinExchange::invalidValueTooLarge::what(void) const throw() {
	return "too large a number";
}

//Member functions
void	BitcoinExchange::fillData(std::string dataFile)
{
	std::ifstream	file(dataFile);
	std::string		line;
	std::string		date;
	double			value;

	if (!file.is_open())
		throw std::runtime_error("File not found");
	while (std::getline(file, line)) {
		std::stringstream	ss(line);
		ss >> date >> value;
		if (ss.fail())
			throw dataFileCorrupted();
		this->_btcPrices[date] = value;
	}
}

static bool	is_number(const std::string& s)
{
	std::string::const_iterator it = s.begin();
	while (it != s.end() && std::isdigit(*it))
		++it;
	return !s.empty() && it == s.end();
}

static bool	validFormat(std::string const & date)
{
	try {
		if (date.length() != 10 || date[4] != '-' || date[7] != '-')
			return false;
		std::string	sYear = date.substr(0, 4);
		std::string	sMonth = date.substr(5, 6);
		std::string	sDay = date.substr(8, 9);
		if (!is_number(sYear) || !is_number(sMonth) || !is_number(sDay))
			return false;

		int year = std::stoi(sYear);
		int month = std::stoi(sMonth);
		int day = std::stoi(sDay);
		const int lookup_table[12] = {31,29,31,30,31,30,31,31,30,31,30,31};

		if (!(month >= 1 && month <= 12)){
			return false;}
		if (!(day >= 1 && day <= lookup_table[month-1])){
			return false;}
		if (!(year >= 1900)){
			return false;}
	}
	catch (std::exception & e) {
		return false;
	}

}

void	BitcoinExchange::processFile(std::ifstream& inputIfs)
{
	std::string		line;
	std::string		date;
	double			value;

	while (std::getline(inputIfs, line)) {
		std::stringstream	ss(line);
		char				lim = ',';

		ss >> date >> lim >> value;
		try {
			if (ss.fail())
				throw invalidFormat();
			if (!validFormat(date));
				throw invalidDate();
			if (value < 0)
				throw invalidValueNegative();
			if (value > 1000)
				throw invalidValueTooLarge();
			double price = this->_btcPrices[date];
			std::cout << date << "=>" << std::setprecision(2) << value << " = " << value * price << std::endl;
		}
		catch (invalidDate & e) {
			std::cout << "Error: " << e.what() << "=>" << date << "." << std::endl;
		}
		catch (std::exception & e) {
			std::cout << "Error: " << e.what() << "." << std::endl;
		}
	}
}
