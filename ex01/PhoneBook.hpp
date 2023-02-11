#include "Contact.hpp"

class PhoneBook {
	private:
		Contact	contact[8];

	public:
		PhoneBook();
		void	add_contact();
		void	search_contact();
		void	exit_();
		~PhoneBook();
};