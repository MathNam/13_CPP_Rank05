#include "Span.hpp"
#include <algorithm>
#include <cstdlib>
#include <exception>
#include <iostream>

using std::cout;
using std::endl;

int	main(void)
{
	cout << endl << "===== Testing incomplete lists =====" << endl << endl;
	{
		try{
			Span sp1 = Span(0);
			sp1.addNumber(45);
			std::cout << sp1.shortestSpan() << std::endl;
		} catch (const std::exception &e) {
			std::cerr << e.what() << endl;
		}
		try{
			Span sp2 = Span(1);
			sp2.addNumber(12);
			std::cout << sp2.longestSpan() << std::endl;
		} catch (const std::exception &e) {
			std::cerr << e.what() << endl;
		}
	}
	cout << endl << "===== Testing full list =====" << endl << endl;
	{
		try{
			Span sp3(3);
			sp3.addNumber(1);
			sp3.addNumber(1);
			sp3.addNumber(1);
			sp3.addNumber(10);
			std::cout << sp3.longestSpan() << std::endl;
		} catch (const std::exception &e){
			std::cerr << e.what() << endl;
		}
	}
	cout << endl << "===== Testing subject main =====" << endl << endl;
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	cout << endl << "===== Testing iterator range =====" << endl << endl;
	{
		std::srand(time(0));
		try {
			std::list<int> range(10);
			std::generate(range.begin(), range.end(), std::rand);
			Span sp(range.size());
			sp.addNumber(range.begin(), range.end());
			cout << sp.shortestSpan() << std::endl;
			cout << sp.longestSpan() << std::endl;
		} catch (const std::exception &e) {
			std::cerr << e.what() << endl;
		}
	}
return 0;
}