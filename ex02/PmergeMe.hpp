#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <ctime>
#include <sstream>

class PmergeMe {
	private:
		std::vector<int>	v;
		std::deque<int>		d;
		int					size;
		// int count;
		PmergeMe(const PmergeMe& obj);
		PmergeMe& operator=(const PmergeMe& obj);
		void	vectorInsertSort(int left, int right);
		void	vectorMerge(int left, int right);
		void	dequeInsertSort(int left, int right);
		void	dequeMerge(int left, int right);
		void	showArg();

	public:
		PmergeMe();
		~PmergeMe();
		int		checkArg(std::string arg);
		void	insertArg(std::string arg);
		void	sortSimulator();
};

#endif
