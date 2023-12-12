#include "PmergeMe.hpp"
#include <iostream>

/*Static functions*/
template <template <typename, typename> class Container>
std::string getContainerName();

template <>
std::string getContainerName<std::vector>()
{
	return "vector<int>";
}

template <>
std::string getContainerName<std::deque>()
{
	return "deque<int>";
}

int	ft_stoa(const char *str)
{
	std::istringstream	ss(str);
	int					number;

	ss >> number;
	return (number);
}

bool	is_number(const std::string& s)
{
	if (s.empty() || s[0] == '-')
		return false;

	size_t i = 0;

	if (s[0] == '+' && s.length() == 1)
		return false;
	else if (s[0] == '+')
		i++;
	for (; i < s.length(); i++) {
		if (!std::isdigit(s[i]))
			return false;
	}
	return true;
}

/*Constructors*/
template <template <typename, typename> class Container>
PmergeMe<Container>::PmergeMe() : _data(), _last(-1), _time(0) {}


template <template <typename, typename> class Container>
PmergeMe<Container>::PmergeMe(char **data) : _data()
{
	_time = 0;
	_last = -1;

	for(size_t i = 0; data[i]; i++) {
		if (!is_number(data[i])) {
			throw std::invalid_argument("Error: invalid argument.");
		}
		_data.push_back(ft_stoa(data[i]));
	}
}

template <template <typename, typename> class Container>
PmergeMe<Container>::PmergeMe(const PmergeMe &other)
{
	_data = other._data;
}

template <template <typename, typename> class Container>
PmergeMe<Container> &PmergeMe<Container>::operator=(const PmergeMe &other)
{
	if (this != &other) {
		_data = other._data;
		_last = other._last;
		_time = other._time;
	}
	return *this;
}

/*Destructors*/
template <template <typename, typename> class Container>
PmergeMe<Container>::~PmergeMe() {}

////////////////////
/*Member functions*/
////////////////////

template <template <typename, typename> class Container>
void	PmergeMe<Container>::print_data() const
{
	for (size_t i = 0; i < _data.size(); i++) {
		std::cout << _data[i] << " ";
	}
	std::cout << std::endl;
}

template <template <typename, typename> class Container>
void	PmergeMe<Container>::benchmark() const
{
	std::cout
			<<	"Time to process a range of " << _data.size()
			<< " elements with std::" << ::getContainerName<Container>()
			<< " : " << std::fixed << std::setprecision(5) << _time << " us"
			<< std::endl;
}

template <template <typename, typename> class Container>
void	PmergeMe<Container>::move(int oldIndex, int newIndex)
{
	if (oldIndex > newIndex)
		std::rotate(_data.rend() - oldIndex - 1, _data.rend() - oldIndex, _data.rend() - newIndex);
	else	
		std::rotate(_data.begin() + oldIndex, _data.begin() + oldIndex + 1, _data.begin() + newIndex + 1);
}

template <template <typename, typename> class Container>
void PmergeMe<Container>::sort()
{
	
	std::clock_t start = std::clock();

	typename Container< int, std::allocator<int> >::iterator first = _data.begin();
	typename Container< int, std::allocator<int> >::iterator last = _data.end();

	int size = std::distance(first, last);
	if (size < 2)
		return;

	bool has_stray = (size % 2 != 0);
	typename Container< int, std::allocator<int> >::iterator end = has_stray ? last - 1 : last;
	if (has_stray)
		--size;

/*------------------------------------------------------------
	Arrange pairs in ascending order
------------------------------------------------------------*/
	{
		typename Container< int, std::allocator<int> >::iterator it = _data.begin();
		for (; it != end ; it += 2) {
			if (it[1] < it[0]) {
				std::iter_swap(it, it + 1);
			}
		}
	}

/*------------------------------------------------------------
	Sort pairs according to largest element (insertion)
------------------------------------------------------------*/
	{
		typename Container< int, std::allocator<int> >::iterator it1 = _data.begin();
		typename Container< int, std::allocator<int> >::iterator it2;
		for (; it1 != end ; it1 += 2) {
			typename Container< int, std::allocator<int> >::iterator itMin = it1;
			for (it2 = it1 + 2; it2 != end ; it2 += 2) {
				if (it2[1] < itMin[1])
					itMin = it2;
			}
			if (itMin != it1) {
				std::iter_swap(it1, itMin);
				std::iter_swap(it1 + 1, itMin + 1);
			}
		}
	}

	std::cout << "Before merge: " << std::endl;
	print_data();
	int	jacobsthalIdxArr[] ={0, 2, 6, 10, 22, 42, 86, 170, 342, 682, 1366, 2730, 5462, 10922, 21846, 43690, 87382, 174762, 349526, 699050, 1398102, 2796202, 5592406, 11184810, 22369622};
	const std::vector<int> jacobsthalIdx = std::vector<int>(jacobsthalIdxArr, jacobsthalIdxArr + sizeof(jacobsthalIdxArr) / sizeof(jacobsthalIdxArr[0]));
// /*------------------------------------------------------------
// 	Merge lowest elements of pairs (Binary search)
// ------------------------------------------------------------*/
	{
		int idx_jacobsthal = std::lower_bound(jacobsthalIdx.begin(), jacobsthalIdx.end(), size)[0];
		std::cout << "idx_jacobsthal: " << idx_jacobsthal << std::endl;
		int i = 1;
		while (jacobsthalIdx[i] <= idx_jacobsthal) {
			int idx_max = std::min(jacobsthalIdx[i], size - 1);
			// std::cout << "idx_max: " << idx_max << std::endl;
			typename Container< int, std::allocator<int> >::reverse_iterator rit = _data.rend() - idx_max - 1;
			// typename Container< int, std::allocator<int> >::reverse_iterator rEnd = _data.rend();
			// for (; rit != rEnd ; rit += 2) {
				std::cout << "rit value: " << *rit << std::endl;
				int idx = binarySearch(idx_max, rit[0]);
				std::cout << "idx: " << idx << std::endl;
				std::cout << "_data.rend() - rit: " << _data.rend() - rit - 1<< std::endl;
				if (idx < _data.rend() - rit - 1)
					move(_data.rend() - rit - 1, idx);
			// }
			i++;
		}
// 			}
// 			i++;
// 		}
	}
/*------------------------------------------------------------
	Insert stray element
------------------------------------------------------------*/
	if (has_stray) {
		int idx = binarySearch(size, _data[size]);
		if (idx < size)
			move(size, idx);
	}

	_time = static_cast<double>(std::clock() - start) / CLOCKS_PER_SEC;
}

template <template <typename, typename> class Container>
int		PmergeMe<Container>::binarySearch(int max_idx, int n)
{
	int	left = 0;
	int	right = max_idx;

	if (n < _data[0])
		return 0;
	if (n > _data[max_idx])
		return max_idx + 1;

	while (left <= right) {
		int	mid = left + (right - left) / 2;

		if (_data[mid] == n)
			return mid;
		if (_data[mid] < n)
			left = mid + 1;
		else
			right = mid - 1;
	}
	return left;
}

// Explicit instantiation: https://stackoverflow.com/a/495021/10372819
template class PmergeMe< std::vector >;
template class PmergeMe< std::deque >;
