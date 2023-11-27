#include "ScalarConverter.hpp"
#include <cctype>
#include <charconv>
#include <cstddef>
#include <iostream>
#include <limits>
#include <sstream>
#include <stdexcept>
#include <string>

#define	PRINT_MSG 0

using std::cout;
using std::endl;

enum literalType {
	_char,
	_int,
	_float,
	_double,
	error
};

static bool	isChar(const std::string& str)
{
	return (str.length() == 1 && std::isprint(str[0]) && !std::isdigit(str[0]));
}

static bool	isInt(const std::string& str)
{
	size_t s = 0;
	if (str.length() > 1 && (str[0] == '-'))
		s++;
	for (size_t i = s; i < str.length(); i++) {
		if (!std::isdigit(str[i]))
			return false;
	}
	return true;
}

static bool	isFloat(const std::string& str)
{
	if (str == "nanf" || str == "+inff" || str == "-inff")
		return true;

	size_t s = 0;
	if (str.length() > 1 && (str[0] == '-'))
		s++;
	for (size_t i = s; i < str.length() - 1; i++) {
		if (str[i] == '.')
			break;
		if (!std::isdigit(str[i]))
			return false;
	}
	for (size_t j = str.find('.') + 1; j < str.length() - 1; j++) {
		if (!std::isdigit(str[j]))
				return false;
	}
	if (str[str.length() - 1] == 'f')
		return true;
	return false;
}

static bool	isDouble(const std::string& str)
{
	if (str == "nan" || str == "+inf" || str == "-inf")
		return true;
	
	size_t s = 0;
	if (str.length() > 1 && (str[0] == '-'))
		s++;
	for (size_t i = s; i < str.length(); i++) {
		if (str[i] == '.')
			break;
		if (!std::isdigit(str[i]))
			return false;
	}
	for (size_t j = str.find('.') + 1; j < str.length(); j++) {
		if (!std::isdigit(str[j]))
			return false;
	}
	return true;
}

static int	getType(const std::string& str)
{
	if (isChar(str))
		return _char;
	if (isInt(str))
		return _int;
	if (isFloat(str))
		return _float;
	if (isDouble(str))
		return _double;
	return error;
}

static void	printChar(char c)
{
	cout << "char: '" << c << "'" << endl;
	cout << "int: " << static_cast<int>(c) << endl;
	cout << "float: " << static_cast<float>(c) << ".0f" << endl;
	cout << "double: " << static_cast<double>(c) << ".0" << endl;
}

static void	printInt(int n)
{
	if (n >= 32 && n <= 126)
		cout << "char: '" << static_cast<char>(n) << "'" << endl;
	else
		cout << "char: Non displayable" << endl;
	cout << "int: " << n << endl;
	cout << "float: " << static_cast<float>(n) << ".0f" << endl;
	cout << "double: " << static_cast<double>(n) << ".0" << endl;
}

static void	printFloat(float n)
{
	if (n >= 32 && n <= 126)
		cout << "char: '" << static_cast<char>(n) << "'" << endl;
	else
		cout << "char: Non displayable" << endl;
	cout << "int: " << static_cast<int>(n) << endl;
	cout << "float: " << n << "f" << endl;
	cout << "double: " << static_cast<double>(n) << endl;
}

static void	printDouble(double n)
{
	if (n >= 32 && n <= 126)
		cout << "char: '" << static_cast<char>(n) << "'" << endl;
	else
		cout << "char: Non displayable" << endl;
	cout << "int: " << static_cast<int>(n) << endl;
	cout << "float: " << static_cast<float>(n) << "f" << endl;
	cout << "double: " << n << endl;
}

static void printPseudoLiteral(literalType dest, const std::string &pseudoLiteral)
{
	cout << "char: impossible" << endl;
	cout << "int: impossible" << endl;
	if (dest == _float)
	{
		cout << "float: " << pseudoLiteral << endl;
		cout << "double: " << pseudoLiteral.substr(0, pseudoLiteral.length() - 1) << endl;
	}
	else if (dest == _double)
	{
		cout << "float: " << pseudoLiteral + "f" << endl;
		cout << "double: " << pseudoLiteral << endl;
	}
}

static int ft_stoi(const std::string &str)
{
	int					number;
	std::stringstream	strStream(str);

	try {
		if (strStream >> number)
			return number;
		throw std::string("the string does not contain a valid integer");
	} catch (std::string const &error) {
		std::cerr << error << endl;
	}
	return (0);
}

static float	ft_stof(const std::string &str)
{
	float				number;
	std::stringstream	strStream(str);

	try {
		if (strStream >> number)
			return number;
		throw std::string("the string does not contain a valid float");
	} catch (std::string const &error) {
		std::cerr << error << endl;
	}
	return (0.0f);
}

static double	ft_stod(const std::string &str)
{
	double				number;
	std::stringstream	strStream(str);

	try {
		if (strStream >> number)
			return number;
		throw std::string("the string does not contain a valid double");
	} catch (std::string const &error) {
		std::cerr << error << endl;
	}
	return (0.0);
}

void	ScalarConverter::convert(std::string const & str)
{
	switch (getType(str)) {
		case _char:
			printChar(str[0]);
			break;
		case _int:
			printInt(ft_stoi(str));
			break;
		case _float:
			if (str == "nanf" || str == "+inff" || str == "-inff")
				printPseudoLiteral(_float, str);
			else
				printFloat(ft_stof(str));
			break;
		case _double:
			if (str == "nan" || str == "+inf" || str == "-inf")
				printPseudoLiteral(_double, str);
			else
				printDouble(ft_stod(str));
			break;
		default:
			cout  << "Unknown type" << endl;
	}
}
