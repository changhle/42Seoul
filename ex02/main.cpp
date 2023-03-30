#include "PmergeMe.hpp"

int	main(int argc, char **argv)
{
	timespec start_time, end_time;
	PmergeMe	pmg;

	if (argc != 2)
	{
		std::cerr << "Argument Error!" << std::endl;
		return (1);
	}
	pmg.insertArg(argv[1]);
	std::cout << "Before: ";
	pmg.showArg();
	clock_gettime(CLOCK_MONOTONIC, &start_time);
	pmg.mergeSort();
	clock_gettime(CLOCK_MONOTONIC, &end_time);
	std::cout << "After: ";
	pmg.showArg();
	long long elapsed_time_ns = (long long)(end_time.tv_sec - start_time.tv_sec) * 1e9 + (end_time.tv_nsec - start_time.tv_nsec);
	std::cout << "Time to process a range of 5 elements with std::[..] : " << elapsed_time_ns << " us" << std::endl;
}