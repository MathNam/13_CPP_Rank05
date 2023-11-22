#ifndef DATA_STRUCT_H
# define DATA_STRUCT_H

# include <string>
# include <stdint.h>

struct Data
{
	unsigned int	value;
	std::string		string;
};

uintptr_t		serialize(Data * ptr);
Data *			deserialize(uintptr_t raw);
std::ostream &	operator<<(std::ostream &stream, const Data & obj);

#endif
