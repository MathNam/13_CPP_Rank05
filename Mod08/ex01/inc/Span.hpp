#ifndef SPAN_CLASS_H
# define SPAN_CLASS_H

# include <cstdlib>
# include <algorithm>
# include <iostream>
# include <exception>
# include <list>
# include <string>
# include <iterator>
# include <numeric>
# include <limits>
# include <climits>
# include <cmath>

class Span {
public:
	Span();
	Span(unsigned int size);
	Span(Span const & cpy);
	~Span();

	Span&	operator=(Span const & rhs);

	void			addNumber(int nb);
	void			addNumber(int arr[], int n);
	void			addNumber(std::list<int> app);
	unsigned int		shortestSpan(void);
	unsigned int		longestSpan(void);

private:
	class tooManyElements : public std::exception {
	public:
		virtual const char * what(void) const throw();
	};
	class noSpanCanBeFound : public	 std::exception {
	public:
		virtual const char * what(void) const throw();
	};
	
	unsigned int	_maxSize;
	std::list<int>	_list;
};

#endif
