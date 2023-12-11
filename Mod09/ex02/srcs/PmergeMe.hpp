#pragma once

#include <iostream>
#include <memory>
#include <vector>
#include <deque>
#include <ctime>
#include <iomanip>
#include <sstream>

/* Type definitions */
typedef std::vector<int> int_vector;

/* Class definition */
template <template <typename, typename> class Container>
class PmergeMe {

public:
	typedef typename std::vector<int, std::allocator<int>>::iterator iterator;
	typedef typename std::vector<int, std::allocator<int>>::const_iterator const_iterator;

	PmergeMe();
	PmergeMe(const PmergeMe &cpy);
	PmergeMe&	operator=(const PmergeMe &rhs);
	PmergeMe(char **data);

	~PmergeMe();

	void	sort();
	void	print_data() const;
	void	benchmark() const;

private:
	static constexpr std::uint_fast64_t jacobsthalIdx[] = {
		2u, 2u, 6u, 10u, 22u, 42u, 86u, 170u, 342u, 682u, 1366u,
		2730u, 5462u, 10922u, 21846u, 43690u, 87382u, 174762u, 349526u, 699050u,
		1398102u, 2796202u, 5592406u, 11184810u, 22369622u, 44739242};

	Container<int, std::allocator<int>>	_data;
	int		_last;
	double	_time;
};
