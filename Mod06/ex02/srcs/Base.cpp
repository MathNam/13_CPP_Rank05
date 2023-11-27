#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <exception>
#include <iostream>
#include <cstdlib>

Base::~Base(void)
{
	return ;
}

Base*	generate()
{
	int nb = rand() % 3;

	char c = "ABC"[nb];

	std::cout << c << " created" << std::endl;
	switch (c) {
		case 'A':
			return new A;
		case 'B':
			return new B;
		case 'C':
			return new C;
	}
	return NULL;
}

void	identify(Base* p)
{
	std::cout << "Base * identify: ";

	if (dynamic_cast<A *>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B * >(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "C" << std::endl;
	return ;
}

void	identify(Base& p)
{
	std::cout << "Base & identify: ";

	try {
		p = dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
	} catch (const std::exception &e) {
		try {
			p = dynamic_cast<B&>(p);
			std::cout << "B" << std::endl;
		} catch (const std::exception &e) {
			std::cout << "C" << std::endl;
		}
	}
	return ;
}