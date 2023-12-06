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
	return "invalid format";
}

const char* BitcoinExchange::invalidDate::what(void) const throw() {
	return "bad input";
}

const char* BitcoinExchange::qtyNegative::what(void) const throw() {
	return "not a positive number.";
}

const char* BitcoinExchange::qtyTooLarge::what(void) const throw() {
	return "too large a number.";
}

const char* BitcoinExchange::dataFileCorrupted::what(void) const throw() {
	return "Data file corrupted.";
}

//Member functions
void	BitcoinExchange::fillData(std::string dataFile)
{
	std::ifstream	file(dataFile.c_str());
	if (!file.is_open())
		throw std::runtime_error("Data file not found");
	
	std::string	line;
	std::string	date;
	int			limPos;
	double		value;

	std::getline(file, line);
	while (std::getline(file, line)) {
		limPos = line.find(",");
		if (limPos != 10)
			throw dataFileCorrupted();
		date = line.substr(0, limPos);
		value = std::strtod(line.substr(limPos + 1, line.length()).c_str(), NULL);
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

static bool	validDate(std::string const & date)
{
	try {
		if (date.length() != 10 || date[4] != '-' || date[7] != '-')
			return false;
		std::string	sYear = date.substr(0, 4);
		std::string	sMonth = date.substr(5, 2);
		std::string	sDay = date.substr(8, 2);
		if (!is_number(sYear) || !is_number(sMonth) || !is_number(sDay))
			return false;

		char* pEnd;
		int year = std::strtol(sYear.c_str(), &pEnd, 10);
		int month = std::strtol(sMonth.c_str(), &pEnd, 10);
		int day = std::strtol(sDay.c_str(), &pEnd, 10);

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
	return true;
}

double	BitcoinExchange::findPrice(std::string const & date)
{
	std::map<std::string, double>::iterator it = _btcPrices.begin();
	while (it != _btcPrices.end()) {
		if (it->first >= date)
			return (--it)->second;
		it++;
	}
	return 0;
}

void	BitcoinExchange::processFile(char* inputFileName)
{
	std::ifstream	file(inputFileName);
	if (!file.is_open())
		throw std::runtime_error("Input file not found");

	std::string		line;
	std::string		date;
	int				limPos;
	double			price;

	std::string		sQty;
	double			qty;


	std::getline(file, line);
	while (std::getline(file, line)) {
		try {
			if (line.empty())
				continue;
			limPos = line.find(" | ");
			if (limPos != 10)
				throw invalidFormat();

			date = line.substr(0, limPos);
			if (!validDate(date))
				throw invalidDate();

			price = findPrice(date);

			sQty = line.substr(limPos + 3, line.length() - limPos + 3);
			qty = std::strtod(sQty.c_str(), NULL);
			if (qty < 0)
				throw qtyNegative();
			if (qty > 1000)
				throw qtyTooLarge();
			std::cout << date << " => " << qty << " = " << qty * price << std::endl;
		}
		catch (invalidDate & e) {
			std::cout << "Error: " << e.what() << " => " << date << "." << std::endl;
		}
		catch (std::exception & e) {
			std::cout << "Error: " << e.what() << "." << std::endl;
		}
	}
}
