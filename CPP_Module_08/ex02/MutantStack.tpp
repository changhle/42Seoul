template <typename T>
MutantStack<T>::MutantStack()
{
	std::cout << "[MutantStack] Default constructor" << std::endl;
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack& obj)
{
	std::cout << "[MutantStack] Copy constructor" << std::endl;
	*this = obj;
}

template <typename T>
MutantStack<T>::~MutantStack()
{
	std::cout << "[MutantStack] Destructor" << std::endl;
}

template <typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack& obj)
{
	std::cout << "[MutantStack] Copy assignment operator" << std::endl;
	*this = obj;
	return (*this);
}

template <typename T>
typename MutantStack<T>::iterator	MutantStack<T>::begin()
{
	return (this->c.begin());
}

template <typename T>
typename MutantStack<T>::const_iterator	MutantStack<T>::cbegin()
{
	return (this->c.cbegin());
}

template <typename T>
typename MutantStack<T>::reverse_iterator	MutantStack<T>::rbegin()
{
	return (this->c.rbegin());
}

template <typename T>
typename MutantStack<T>::const_reverse_iterator	MutantStack<T>::crbegin()
{
	return (this->c.crbegin());
}

template <typename T>
typename MutantStack<T>::iterator	MutantStack<T>::end()
{
	return (this->c.end());
}

template <typename T>
typename MutantStack<T>::const_iterator	MutantStack<T>::cend()
{
	return (this->c.cend());
}

template <typename T>
typename MutantStack<T>::reverse_iterator	MutantStack<T>::rend()
{
	return (this->c.rend());
}

template <typename T>
typename MutantStack<T>::const_reverse_iterator	MutantStack<T>::crend()
{
	return (this->c.end());
}
