#ifndef SERIALIZER_H
# define SERIALIZER_H

# include <stdint.h>
# include <iostream>

typedef struct s_data
{
	int	number;
}	Data;

class Serializer {
public:
	static uintptr_t	serialize(Data* ptr);
	static Data*		deserialize(uintptr_t raw);

private:
	Serializer();
	Serializer(const Serializer& toCopy);
	~Serializer();

	Serializer&	operator=(const Serializer& rhs);
};

#endif
