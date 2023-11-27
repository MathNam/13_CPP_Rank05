#include "Serializer.hpp"
#include <stdint.h>

int main() {

	Data data;
	data.number = 42;

	uintptr_t ptr = Serializer::serialize(&data);
	std::cout << "Ptr -> " << ptr << std::endl;

	Data *data_recovered = Serializer::deserialize(ptr);
	std::cout << "Data recovered : " << data.number << std::endl;

	uintptr_t ptr2 = Serializer::serialize(data_recovered);
	std::cout << "Ptr2-> " << ptr2 << std::endl;

	return 0;
}