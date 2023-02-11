#include "Contact.hpp"

class PhoneBook {
	private:
		int		index;
		Contact	contact[8];

	public:
		PhoneBook();
		void	add();
		void	search();
		// ~PhoneBook();
};