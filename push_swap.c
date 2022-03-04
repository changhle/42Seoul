#include "push_swap.h"

int	argv_len(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
		i++;
	return (i);
}

void	error(int n)
{
	if (n > 0)
	{
		write(1, "Error\n", 6);
		exit(1);
	}
}

int	get_argv_size(char **argv)
{
	int	size;

	size = 0;
	while (argv[size])
		size++;
	return (size);
}

void	check_error(int	*arr, int argv_size, char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (i < argv_size)
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j++]))
				error(1);
		}
		arr[i] = ft_atoll(argv[i]);
		if (arr[i] > INT_MAX || arr[i] < INT_MIN)
			error(1);
		j = 0;
		while (j < i)
		{
			if (arr[i] == arr[j++])
				error(1);
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	i;
	int	*arr;
	int	argv_size;

	i = 0;
	argv = ft_split(argv[1], ' ');
	argv_size = get_argv_size(argv);
	printf("----\n");
	arr = (int *)malloc(argv_size * sizeof(int));
	check_error(arr, argv_size, argv);
	printf("-----\n");
	i = 0;
	while (arr[i])
		printf("%d ", arr[i++]);
	printf("\n");
}