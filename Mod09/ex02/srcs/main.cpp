#include "PmergeMe.hpp"

int main(int ac, char** av) {

	if (ac < 2) {
		std::cout << "Usage: " << av[0] << " <positive integer sequence>" << std::endl;
		return EXIT_FAILURE;
	}

	try {
		PmergeMe<std::vector<int> > v(av + 1);

		std::cout << "Before:\t";
		v.print_data();
		v.sort();

		PmergeMe<std::deque<int> > dq(av + 1);
		dq.sort();
		
		std::cout << "After:\t";
		dq.print_data();

		v.benchmark();
		dq.benchmark();
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	return EXIT_SUCCESS;
}