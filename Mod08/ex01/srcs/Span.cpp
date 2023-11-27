#include "Span.hpp"


Span::Span(void) :
	_maxSize(0),
	_list(_maxSize)
{
	return ;
}

Span::Span(unsigned int N) :
	_maxSize(N),
	_list(_maxSize)
{
	return ;
}

Span::Span(Span const & src) :
	_maxSize(src._maxSize),
	_list(src._list)
{
	return ;
}

Span::~Span(void)
{
	return ;
}

const char * Span::tooManyElements::what(void) const throw()
{
	return "Too many elements added.";
}

const char * Span::noSpanCanBeFound::what(void) const throw()
{
	return "No span can be found, list is empty or only contains one element.";
}

Span&	Span::operator=(Span const & src)
{
	if (this != & src) {
		this->_maxSize = src._maxSize;
		this->_list.clear();
		this->_list.insert(this->_list.end(),
			src._list.begin(), src._list.end());
	}
	return (*this);
}

void	Span::addNumber(int nb)
{
	if (this->_list.size() >= this->_maxSize)
		throw (Span::tooManyElements());
	this->_list.push_back(nb);
}

void	Span::addNumber(int arr[], int n)
{
	if (this->_list.size() + n > this->_maxSize)
		throw (Span::tooManyElements());
	for (int i = 0; i < n; i++) {
			this->_list.push_back(arr[i]);
	}
}

void	Span::addNumber(std::list<int> app)
{
	if (this->_list.size() + app.size() > this->_maxSize)
		throw (Span::tooManyElements());
	this->_list.insert(this->_list.end(), app.begin(), app.end());
}

unsigned int	Span::shortestSpan(void)
{
	std::list<int>::iterator	it;
	int							prev;
	int							min = INT_MAX;

	this->_list.sort();
	prev = *it;
	it++;
	for (it = this->_list.begin(); it != this->_list.end(); it++) {
		min = std::min(min, *it - prev);
		prev = *it;
	}
	return min;
}

unsigned int	Span::longestSpan(void)
{
	this->_list.sort();
	return this->_list.front() - this->_list.back();
}
