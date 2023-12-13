#pragma once

#include <iostream>
#include <memory>
#include <vector>
#include <deque>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <iterator>
#include <algorithm>
#include <cstddef>

/* Class definition */
template <template <typename, typename> class Container>
class PmergeMe {

public:

	PmergeMe();
	PmergeMe(const PmergeMe &cpy);
	PmergeMe&	operator=(const PmergeMe &rhs);
	PmergeMe(char **data);

	~PmergeMe();

	void	sort();
	void	print_data() const;
	void	print_sortedData() const;
	void	benchmark() const;

private:
	Container< int, std::allocator<int> >	_data;
	Container< int, std::allocator<int> >	_sortedData;
	
	int		_last;
	double	_time;

	bool	is_sorted() const;
	int		binarySearch(int max_idx, int n);
};
