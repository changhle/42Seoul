#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
	len	= 0;
	count = 0;
}

PmergeMe::~PmergeMe() {}

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
		d.push_back(num);
		len++;
	}
}

void	PmergeMe::sortSimulator()
{
	clock_t v_start, v_end;
	clock_t d_start, d_end;	

	std::cout << "Before: ";
	showArg();
	v_start = clock();
	vectorMerge(0, len - 1);
	v_end = clock();
	d_start = clock();
	dequeMerge(0, len - 1);
	d_end = clock();
	std::cout << "After: ";
	showArg();
	std::cout << "Time to process a range of 5 elements with std::vector : " << v_end - v_start << " ms" << std::endl;
	std::cout << "Time to process a range of 5 elements with std::deque : " << d_end - d_start << " ms" << std::endl;
}

void	PmergeMe::vectorInsertSort(int left, int right)
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

void	PmergeMe::vectorMerge(int left, int right)
{
	int	mid = (left + right) / 2;
	int	i = left;
	int	j = mid + 1;
	std::vector<int>	v_sorted;

	if (right - left < 100)
		return (vectorInsertSort(left, right));
	else
	{
		vectorMerge(left, mid);
		vectorMerge(mid + 1, right);
	}
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

void	PmergeMe::dequeInsertSort(int left, int right)
{
	int	i, j;
	int	key;

	for (i = left + 1; i <= right; i++)
	{
		key = d[i];
		for (j = i - 1; j >= left && d[j] > key; j--)
			d[j + 1] = d[j];
		d[j + 1] = key;
	}
	count++;
}

void	PmergeMe::dequeMerge(int left, int right)
{
	int	mid = (left + right) / 2;
	int	i = left;
	int	j = mid + 1;
	std::deque<int>	d_sorted;

	if (right - left < 100)
		return (dequeInsertSort(left, right));
	else
	{
		dequeMerge(left, mid);
		dequeMerge(mid + 1, right);
	}
	while (i <= mid && j <= right)
	{
		if (d[i] > d[j])
			d_sorted.push_back(d[j++]);
		else
			d_sorted.push_back(d[i++]);
	}
	if (i > mid)
	{
		for (int k = j; k <= right; k++)
			d_sorted.push_back(d[k]);
	}
	else
	{
		for (int k = i; k <= mid; k++)
			d_sorted.push_back(d[k]);
	}
	for (int k = left; k <= right; k++)
		d[k] = d_sorted[k - left];
}

void	PmergeMe::showArg()
{
	for (int i = 0; i < len && (v[i] == d[i]); i++)
		std::cout << v[i] << " ";
	std::cout << std::endl;
}