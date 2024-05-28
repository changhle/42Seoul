template <typename T>
Array<T>::Array() : array(NULL), arraySize(0) {
	std::cout << "[Array] Default constructor" << std::endl;
}

template <typename T>
Array<T>::Array(unsigned int n) {
	std::cout << "[Array] constructor" << std::endl;
	array = new T[n];
	arraySize = n;
}

template <typename T>
Array<T>::Array(const Array& obj) {
	std::cout << "[Array] Copy constructor" << std::endl;
	array = new T[obj.size()];
	arraySize = obj.size();
	for (unsigned int i = 0; i < arraySize; i++)
		array[i] = obj.array[i];
}

template <typename T>
Array<T>::~Array() {
	std::cout << "[Array] Destructor" << std::endl;
	delete [] array;
	array = NULL;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& obj) {
	std::cout << "[Array] Copy assignment operator" << std::endl;
	if (array != NULL)
	{
		delete [] array;
		array = NULL;	
	}
	array = new T[obj.size()];
	arraySize = obj.size();
	for (unsigned int i = 0; i < arraySize; i++)
		array[i] = obj.array[i];
	return (*this);
}

template <typename T>
T&	Array<T>::operator[](unsigned int index)
{
	if (this->arraySize <= index)
		throw Array<T>::IndexException();
	return (this->array[index]);
}

template <typename T>
const T&	Array<T>::operator[](unsigned int index) const
{
	if (this->arraySize <= index)
		throw Array<T>::IndexException();
	return (this->array[index]);
}

template <typename T>
unsigned int	Array<T>::size() const
{
	return (this->arraySize);
}

template <typename T>
const char* Array<T>::IndexException::what() const throw()
{
	return ("[Array] Error : index over");
}