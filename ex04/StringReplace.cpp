
StringReplace::StringReplace() {
	std::cout << "[StringReplace] Default constructor" << '\n';
}
StringReplace::StringReplace(const StringReplace& obj) {
	std::cout << "[StringReplace] Copy constructor" << '\n';
}
StringReplace::~StringReplace() {
	std::cout << "[StringReplace] Destructor" << '\n';
}
StringReplace& StringReplace::operator=(const StringReplace& obj) {
	std::cout << "[StringReplace] Copy assignment operator" << '\n';
	return (*this);
}