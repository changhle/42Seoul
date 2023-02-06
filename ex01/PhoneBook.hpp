#include <iostream>
#include "Contact.hpp"

class PhoneBook {
	private:
		Contact	contact[8];

	public:
		PhoneBook();
		void	Add();
		void	Search();
		void	Exit();
};