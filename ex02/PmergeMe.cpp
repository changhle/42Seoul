#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {count = 0;}
PmergeMe::~PmergeMe() {}
// PmergeMe::PmergeMe(const PmergeMe& obj) {
// 	std::cout << "[PmergeMe] Copy constructor" << '\n';
// }
// PmergeMe& PmergeMe::operator=(const PmergeMe& obj) {
// 	std::cout << "[PmergeMe] Copy assignment operator" << '\n';
// 	return (*this);
// }

void	PmergeMe::insertArg(std::string arg)
{
	std::stringstream	ss(arg);
	std::string			temp;

	while (getline(ss, temp, ' '))
	{
		int					num;
		std::stringstream	ss_int(temp);
		ss_int >> num;
		v.push_back(num);
	}
	len = v.size();
}

void	PmergeMe::mergeSort()
{
	vectorMergeSort(0, len - 1);
}

void	PmergeMe::insertSort(int left, int right)
{
	int	i, j;
	int	key;

	for (i = left + 1; i <= right; i++)
	{
		key = v[i];
		for (j = i - 1; j >= left && v[j] > key; j--)
			v[j + 1] = v[j];
		v[j + 1] = key;
	}
	count++;
}

void	PmergeMe::vectorMergeSort(int left, int right)
{
	int	mid;
	int	i, j;
	std::vector<int>	v_sorted;

	if (right - left < 100)
		return (insertSort(left, right));
	mid = (left + right) / 2;
	if (left >= right)
		return;
	else
	{
		vectorMergeSort(left, mid);
		vectorMergeSort(mid + 1, right);
	}
	i = left;
	j = mid + 1;
	while (i <= mid && j <= right)
	{
		if (v[i] > v[j])
			v_sorted.push_back(v[j++]);
		else
			v_sorted.push_back(v[i++]);
	}
	if (i > mid)
	{
		for (int k = j; k <= right; k++)
			v_sorted.push_back(v[k]);
	}
	else
	{
		for (int k = i; k <= mid; k++)
			v_sorted.push_back(v[k]);
	}
	for (int k = left; k <= right; k++)
		v[k] = v_sorted[k - left];
}

void	PmergeMe::showArg()
{
	for (int i = 0; i < len; i++)
		std::cout << v[i] << " ";
	std::cout << std::endl;
	std::cout << "count : " << count << std::endl;
}