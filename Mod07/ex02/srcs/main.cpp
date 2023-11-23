#include <cstdlib>
#include <exception>
#include <iostream>
#include "Array.hpp"

using std::cout;
using std::endl;

#define MAX_VAL 750
int main(int, char**)
{
	cout << endl << "===== Empty array =====" << endl << endl;
	{
		Array<float> emptyArray;
		try{
			cout << emptyArray[0] << endl;
			cout << emptyArray[2000] << endl;
		} catch (const std::exception &e){
			std::cerr << e.what() << endl;
		}
	}
	cout << endl << "===== String array =====" << endl << endl;
	{
		Array<std::string> strArray(5);
		strArray[0] = "abc";
		strArray[1] = "def";
		strArray[2] = "ghi";
		strArray[3] = "jkl";
		strArray[4] = "mno";
		try{
			for(unsigned int i = 0; i < 6; i++)
				cout << strArray[i] << endl;
		} catch (const std::exception &e) {
			std::cerr << e.what() << endl;
		}
		cout << endl << "===== Array copy =====" << endl << endl;
		Array<std::string> copy(strArray);
		strArray[0] = "1";
		strArray[1] = "2";
		strArray[2] = "3";
		strArray[3] = "4";
		strArray[4] = "5";
		try{
			for(unsigned int i = 0; i < 5; i++)
			{
				cout << "original :\t" << strArray[i] << endl;
				cout << "copy :\t\t" << copy[i] << endl;
			}
		} catch (const std::exception &e) {
			std::cerr << e.what() << endl;
		}
		cout << endl << "===== Assignment operator =====" << endl << endl;
		copy = strArray;
		try{
			for(unsigned int i = 0; i < 5; i++)
				cout << copy[i] << endl;
		} catch (const std::exception &e) {
			std::cerr << e.what() << endl;
		}
	}
	cout << endl << "===== Subject test =====" << endl << endl;
	{
		Array<int> numbers(MAX_VAL);
		int* mirror = new int[MAX_VAL];
		srand(time(NULL));
		for (int i = 0; i < MAX_VAL; i++)
		{
			const int value = rand();
			numbers[i] = value;
			mirror[i] = value;
		}
		//SCOPE
		{
			Array<int> tmp = numbers;
			Array<int> test(tmp);
		}

		for (int i = 0; i < MAX_VAL; i++)
		{
			if (mirror[i] != numbers[i])
			{
				std::cerr << "didn't save the same value!!" << std::endl;
				return 1;
			}
		}
		try
		{
			numbers[-2] = 0;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		try
		{
			numbers[MAX_VAL] = 0;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

		for (int i = 0; i < MAX_VAL; i++)
		{
			numbers[i] = rand();
		}
		delete [] mirror;
	}
	return 0;
}