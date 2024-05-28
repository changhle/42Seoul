#include "Serializer.hpp"

// Serializer::Serializer() {
// 	std::cout << "[Serializer] Default constructor" << '\n';
// }
// Serializer::Serializer(const Serializer& obj) {
// 	std::cout << "[Serializer] Copy constructor" << '\n';
// }
// Serializer::~Serializer() {
// 	std::cout << "[Serializer] Destructor" << '\n';
// }
// Serializer& Serializer::operator=(const Serializer& obj) {
// 	std::cout << "[Serializer] Copy assignment operator" << '\n';
// 	return (*this);
// }

uintptr_t	Serializer::serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data*	Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}