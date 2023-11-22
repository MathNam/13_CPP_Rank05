#ifndef CONVERTER_CLASS_H
# define CONVERTER_CLASS_H

# include <cctype>
# include <cstdlib>
# include <iomanip>
# include <iostream>
# include <limits>
# include <string>

class ScalarConverter
{
public:
	static void	convert(std::string const & str);

protected:
	ScalarConverter(void);
	ScalarConverter(ScalarConverter const & src);
	~ScalarConverter();
};

std::ostream &	operator<<(std::ostream & os, ScalarConverter const & converter);

#endif