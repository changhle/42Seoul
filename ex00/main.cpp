#include "easyfind.hpp"
#include <vector>

int	main()
{
	std::vector<int>			vec;
	std::vector<int>::iterator	vec_iter;

	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);

	vec_iter = easyfind(vec, 1);
	std::cout << "Find : " << *vec_iter << std::endl;
	vec_iter = easyfind(vec, 4);
	std::cout << "Find : " << *vec_iter << std::endl;
	std::cout << std::endl;

	try
	{
		vec_iter = easyfind(vec, 6);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}