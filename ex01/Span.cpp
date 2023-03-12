#include "Span.hpp"

Span::Span(unsigned int N)
{
	std::cout << "[Span] constructor" << std::endl;
	this->N = N;
}

Span::Span(const Span& obj)
{
	std::cout << "[Span] Copy constructor" << std::endl;
	*this = obj;
}

Span::~Span()
{
	std::cout << "[Span] Destructor" << std::endl;
}

Span& Span::operator=(const Span& obj)
{
	std::cout << "[Span] Copy assignment operator" << std::endl;
	N = obj.N;
	vec = obj.vec;
	return (*this);
}

void	Span::addNumber(int num)
{
	if (vec.end() )
}
int		shortestSpan();
int		longestSpan();