#include "ScalarConverter.hpp"

#define	PRINT_MSG 0

enum literal_type {
    error,
    _pseudo_literal,
    _char,
    _int,
    _float,
    _double,
};

static bool	isChar(const std::string& str)
{
	return (str.length() == 1 && std::isprint(str[0]));
}

static bool	isInt(const std::string& str)
{
	if (str.length() == 1 && !std::isdigit(str[0]))
		return true;
	if (str.length() > 1 && (str[0] == '+' || str[0] == '-')) {
		for (size_t i = 1; i < str.length(); i++) {
			if (!std::isdigit(str[i]))
				return false;
		}
		return true;
	}
}

static bool	isFloat(const std::string& str)
{
	if (str.length() == 1 && !std::isdigit(str[0]))
		return true;
	if (str.length() > 1 && (str[0] == '+' || str[0] == '-')) {
		for (size_t i = 1; i < str.length(); i++) {
			if (!std::isdigit(str[i]))
				break;
		}
		for (size_t j = str.find('.') + 1; j < str.length(); j++) {
			if (!std::isdigit(str[j]))
					break;
		}
		if (str[str.length() - 1] == 'f')
			return true;
		return false;
	}
}

static bool	isDouble(const std::string& str)
{
	if (str == "nan" || str == "nanf" || str == "+inf" || str == "+inff" || str == "-inf" || str == "-inff")
		return true;
	if (str.length() == 1 && !std::isdigit(str[0]))
		return true;
	if (str.length() > 1 && (str[0] == '+' || str[0] == '-')) {
		for (size_t i = 1; i < str.length(); i++) {
			if (!std::isdigit(str[i]))
				break;
		}
		for (size_t j = str.find('.') + 1; j < str.length(); j++) {
			if (!std::isdigit(str[j]))
				return false;
		}
		return true;
	}
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

void	ScalarConverter::convert(std::string const & str)
{
	getType()
}
