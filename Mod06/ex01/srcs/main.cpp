#include "Data.hpp"
#include <iostream>

int	main(void)
{
	Data	data = {.value = 12345, .string = "Hello World!"};
	uintptr_t	serializedPointerAsInt = serialize(&data);
	Data *		deserializedPointer = deserialize(serializedPointerAsInt);

}
