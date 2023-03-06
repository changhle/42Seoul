#include "Base.hpp"

int	main()
{
	Base *a;
	Base *b;
	Base *c;

	srand(time(NULL));
	
	a = generate();
	b = generate();
	c = generate();

	identify(a);
	identify(b);
	identify(c);

	identify(*a);
	identify(*b);
	identify(*c);

	delete a;
	delete b;
	delete c;
	return (0);
}