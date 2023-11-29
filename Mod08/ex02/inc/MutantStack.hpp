#ifndef MUTANT_STACK_CLASS_H
# define MUTANT_STACK_CLASS_H

# include <cstdlib>
# include <algorithm>
# include <iostream>
# include <exception>
# include <list>
# include <string>
# include <iterator>
# include <numeric>
# include <limits>
# include <climits>
# include <cmath>
# include <stack>

template<typename T>
class MutantStack : public std::stack<T>
{
public:
	MutantStack() {}
	MutantStack(const MutantStack<T>& src) { *this = src; }
	~MutantStack() {}
	MutantStack<T>& operator=(const MutantStack<T>& rhs) {
		this->c = rhs.c;
		return *this;
	}

	typedef typename std::stack<T>::container_type::iterator iterator;

	iterator begin() { return this->c.begin(); }
	iterator end() { return this->c.end(); }
};

#endif
