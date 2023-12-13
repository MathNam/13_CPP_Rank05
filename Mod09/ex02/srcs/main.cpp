#include "PmergeMe.hpp"

int main(int ac, char* av[]) {

	if (ac < 2) {
		std::cout << "Usage: " << av[0] << " <positive integer sequence>" << std::endl;
		return EXIT_FAILURE;
	}

	try {
		PmergeMe<std::vector> v(av + 1);

		std::cout << "Before:\t";
		v.print_data();

		std::cout << std::endl << "------Sorting: < vector >------" << std::endl;
		v.sort();
		std::cout << "After:\t" << std::endl;
		v.print_sortedData();

		std::cout << std::endl << "------Sorting: < deque >------" << std::endl;
		PmergeMe<std::deque> dq(av + 1);
		dq.sort();
		
		std::cout << "After:\t" << std::endl;
		dq.print_sortedData();

		std::cout << std::endl << "------Benchmark: < vector >------" << std::endl;
		v.benchmark();
		std::cout << std::endl << "------Benchmark: < deque >------" << std::endl;
		dq.benchmark();
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	return EXIT_SUCCESS;
}
