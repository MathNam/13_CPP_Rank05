#include "PmergeMe.hpp"
#include "utils.hpp"
#include <cstring>
# include <vector>
# include <deque>

int main(int ac, char *av[])
{
	if (ac < 2) {
		std::cout << "Invalid parameters" << std::endl;
		return 1;
	}
	try{
		PmergeMe<std::vector<int>> instance;
		Instance.sort();
	} catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}
