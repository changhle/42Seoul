#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base	*generate(void)
{
	int	n = rand() % 3;

	switch (n)
	{
		case 0:
			return (new A);
			break;
		case 1:
			return (new B);
			break;
		case 2:
			return (new C);
			break;
		default:
			return (NULL);
			break;
	}
}

void	identify(Base* p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "A class!" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "B class!" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "C class!" << std::endl;
}

void	identify(Base& p)
{
	try
	{
		static_cast<void>(dynamic_cast<A &>(p));
		std::cout << "A class!" << std::endl;
	}
	catch(std::exception &e) {}
	try
	{
		static_cast<void>(dynamic_cast<B &>(p));
		std::cout << "B class!" << std::endl;
	}
	catch(std::exception &e) {}
	try
	{
		static_cast<void>(dynamic_cast<C &>(p));
		std::cout << "C class!" << std::endl;
	}
	catch(std::exception &e) {}
}

Base::~Base() {}