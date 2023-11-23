#include "Iter.hpp"
#include <string>

int main(void)
{
	int			int_array[] = {123, 456, 789};
	std::string	str_array[] = {"abc", "def", "ghi", "jkl"};

	::iter(int_array, 3, &::print<int>);
	::iter(str_array, 4, &::print<std::string>);

	return 0;
}