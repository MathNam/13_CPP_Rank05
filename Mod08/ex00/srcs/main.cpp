#include "easyfind.hpp"
#include <iostream>
#include <list>
#include <vector>


int main(int argc, char **argv)
{
	if ( argc != 2 ) {
		std::cout << "invalid arguments" << std::endl;
		return 0;
	}

	int	arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	std::vector<int> vect(arr ,arr  + sizeof(arr) / sizeof(int));
	std::list<int> list(arr ,arr  + sizeof(arr) / sizeof(int));

	easyfind( vect, std::atoi( argv[1] ));
	easyfind( list, std::atoi( argv[1] ));

	return 0;
}