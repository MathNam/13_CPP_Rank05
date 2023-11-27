#ifndef EASYFIND_TPP_H
# define EASYFIND_TPP_H

# include <algorithm>
# include <iterator>
# include <stdexcept>
# include <iostream>

template <typename T>
int	easyfind(T& x, int toFind)
{
	if (std::find(x.begin(), x.end(), toFind) != x.end()){
		std::cout << "Found." << std::endl;
		return 1;
	}
	std::cout << "Not found." << std::endl;
	return 0;
}

#endif