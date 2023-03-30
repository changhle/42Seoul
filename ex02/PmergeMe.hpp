#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <sstream>

class PmergeMe {
	private:
		std::vector<int>	v;
		int					len;
		int count;
		PmergeMe(const PmergeMe& obj);
		PmergeMe& operator=(const PmergeMe& obj);

	public:
		PmergeMe();
		~PmergeMe();
		void	insertArg(std::string arg);
		void	mergeSort();
		void	insertSort(int left, int right);
		void	vectorMergeSort(int left, int right);
		void	showArg();
};

#endif
