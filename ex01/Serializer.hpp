#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>

typedef struct	data_s
{
	std::string	str;
} Data;

class Serializer {
	private:
		Serializer();
		Serializer(const Serializer& obj);
		~Serializer();
		Serializer& operator=(const Serializer& obj);

	public:
		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);
};

#endif