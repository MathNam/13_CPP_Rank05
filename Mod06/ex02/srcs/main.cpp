#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

using std::cout;

int	main(void)
{
	Base*	p;
	srand(time(0));

	for (int i = 0; i < 25; i++) {
		std::cout << "Test [" << i << "]: ";
		p = generate();
		identify(p);
		identify(*p);
		delete (p);
		std::cout << std::endl;
	}
	return (0);
}
