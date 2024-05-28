#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <list>

template <typename T>
class MutantStack : public std::stack<T> {
	public:
		typedef typename std::stack<T>::container_type::iterator				iterator;
		typedef typename std::stack<T>::container_type::const_iterator			const_iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator		reverse_iterator;
		typedef typename std::stack<T>::container_type::const_reverse_iterator	const_reverse_iterator;
		MutantStack();
		MutantStack(const MutantStack& obj);
		~MutantStack();
		MutantStack&			operator=(const MutantStack& obj);
		iterator				begin();
		const_iterator			cbegin();
		reverse_iterator		rbegin();
		const_reverse_iterator	crbegin();
		iterator				end();
		const_iterator			cend();
		reverse_iterator		rend();
		const_reverse_iterator	crend();
};

#include "MutantStack.tpp"

#endif
