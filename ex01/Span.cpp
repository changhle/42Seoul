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
	if (vec.size() >= N)
		throw std::out_of_range("Cannot add any more");
	vec.push_back(num);
}

void	Span::addRandNumber(unsigned int size)
{
	if (vec.size() + size > N)
		throw std::out_of_range("Cannot add any more");
	srand(time(NULL));
	for (unsigned int i = 0; i < size; i++)
	{
		vec.push_back(rand() % 1000000);
	}
}

int	Span::shortestSpan()
{
	if (vec.size() < 2)
		throw std::range_error("Size is less than 2");
	std::vector<int>	tmp = vec;
	std::sort(tmp.begin(), tmp.end());
	std::adjacent_difference(tmp.begin(), tmp.end(), tmp.begin());
	return (*std::min_element(tmp.begin() + 1, tmp.end()));
}

int	Span::longestSpan()
{
	if (vec.size() < 2)
		throw std::range_error("Size is less than 2");
	return (*std::max_element(vec.begin(), vec.end()) - *std::min_element(vec.begin(), vec.end()));
}