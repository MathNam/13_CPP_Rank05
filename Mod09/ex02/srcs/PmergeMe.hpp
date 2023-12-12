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

/* Type definitions */
typedef std::vector<int> int_vector;

/* Class definition */
template <template <typename, typename> class Container>
class PmergeMe {

public:
	typedef typename std::vector< int, std::allocator<int> >::iterator iterator;
	typedef typename std::vector< int, std::allocator<int> >::const_iterator const_iterator;

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

	int		binarySearch(int max_idx, int n);
};
