#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <numeric>

class Span {
	private:
		std::vector<int>	vec;
		unsigned int		N;
		Span();
	public:
		Span(unsigned int N);
		Span(const Span& obj);
		~Span();
		Span&	operator=(const Span& obj);
		void	addNumber(int num);
		int		shortestSpan();
		int		longestSpan();
};

#endif
