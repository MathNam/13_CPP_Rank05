#include "PmergeMe.hpp"

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
			throw std::invalid_argument("Error");
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

/*Sort*/
template <template <typename, typename> class Container>
using MyCont = Container<int, std::allocator<int>>;

template <template <typename, typename> class Container>
void PmergeMe<Container>::sort()
{
	std::clock_t start = std::clock();

	typename MyCont<Container>::iterator first = _data.begin();
	typename MyCont<Container>::iterator last = _data.end();

	size_t size = std::distance(first, last);
	if (size < 2)
		return;

	bool has_stray = (size % 2 != 0);

	typename MyCont<Container>::iterator end = has_stray ? std::prev(last) : last;
	typename MyCont<Container>::iterator it = first;
	for (; it != end ; it += 2) {
		if (it[1] < it[0]) {
			std::iter_swap(it, std::next(it));
		}
	}


	_time = static_cast<double>(std::clock() - start) / CLOCKS_PER_SEC;
}


// Explicit instantiation: https://stackoverflow.com/a/495021/10372819
template class PmergeMe< std::vector >;
template class PmergeMe< std::deque >;
