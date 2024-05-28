#include "Serializer.hpp"

int	main()
{
	Data		a;
	Data		*b;
	uintptr_t	ptr;

	a.str = "I'm Data struct!";
	std::cout << "a : " << a.str << std::endl;
	ptr = Serializer::serialize(&a);
	std::cout << "ptr : " << ptr << std::endl;
	b = Serializer::deserialize(ptr);
	std::cout << "b : " << b->str << std::endl;
	std::cout << std::endl;

	if (&a == b)
		std::cout << "Success!!!" << std::endl;
}