#include "Contact.hpp"

#define ADD		1
#define SEARCH	2
#define EXIT	0

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