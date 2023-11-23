#ifndef WHATEVER_H
# define WHATEVER_H

# include <iostream>

template <typename T>
void	swap(T &a, T &b) {
	T	tmp = a;

	a = b;
	b = tmp;
	return ;
}

template <typename T>
T const & max(T const &a, T const &b) {
	if (a > b)
		return (a);
	return (b);
}

template <typename T>
T const & min(T const &a, T const &b) {
	if (a < b)
		return (a);
	return (b);
}

#endif