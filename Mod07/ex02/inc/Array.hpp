#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <stdexcept>
#include <exception>
#include <iostream>
#include <string>
#include <cstdlib>

template <typename T>
class Array {
public:
	Array();
	Array(unsigned int n);
	Array(Array const & src);
	~Array();

	Array&	operator=(Array const & rhs);
	T&		operator[](size_t index);

	size_t 	size(void);

private:
	class outOfBound : public std::exception {
		public:
			virtual const char *what(void) const throw();
	};

	T*		_arr;
	size_t 	_size;
};

template <typename T>
Array<T>::Array(void) : _arr(NULL), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : _arr(new T[n]), _size(n) {}

template <typename T>
Array<T>::Array(Array<T> const & src) : _arr(new T[src._size]), _size(src._size)
{
	for (size_t i = 0; i < this->_size ; i++)
		_arr[i] = src._arr[i];
}

template <typename T>
Array<T>&	Array<T>::operator=(Array<T> const & rhs)
{
	if (this == &rhs)
		return *this;
	delete [] this->_arr;
	this->_size = rhs._size;
	this->_arr = new T[this->_size];
	for (size_t i = 0; i < this->_size; i++)
		this->_arr[i] = rhs._arr[i];
	return *this;
}

template <typename T>
T&	Array<T>::operator[](size_t idx)
{
	if (idx < 0 || idx >= this->_size)
		throw (Array<T>::outOfBound());
	return (this->_arr[idx]);
}

template <typename T>
Array<T>::~Array(void)
{
	delete [] _arr;
}

template <typename T>
const char*	Array<T>::outOfBound::what(void) const throw()
{
	return ("Index out of bound.");
}

template <typename T>
size_t Array<T>::size(void)
{
	return this->_size;
}

#endif