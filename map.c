#include "so_long.h"
#include "./libft/libft.h"
#include "./get_next_line/get_next_line.h"

// void	print_error(int errno)
// {
// 	if (errno == 1)
// 		perror("map_file_name error");
// 	else if (errno == 2)
// 		perror("There is no exit");
// 	else if (errno == 3)
// 		perror("There is no collect");
// 	else if (errno == 4)
// 		perror("There is no player");
// 	exit(1);
// }

void	print_error(char *str)
{
}

char	*delete_newline(char *str)
{
	int	str_len;

	str_len = ft_strlen(str);
	if (str[str_len - 1] == '\n')
		str[str_len - 1] = '\0';
	return (str);
}

void	check_filename(char *filename)
{
	if (ft_strncmp((filename + ft_strlen(filename) - 4), ".ber", 4))
		print_error("");
}

void	get_map(char *filename, t_info *info)
{
	int 	fd;
	// int		byte;
	// char	map[100];
	char	*str;

	fd = open(filename, O_RDONLY);
	// byte = read(fd, map, 100);
	// info->map = delete_newline(map);
	// while (byte > 0)
	// {
	// 	byte = read(fd, map, 100);
	// 	delete_newline(map);
	// 	info->map = ft_strjoin(info->map, map);
	// }
	// printf("%d\n", fd);
	// read(fd, a, 10);
	str = get_next_line(fd);
	// printf("%s\n%s\n%s\n", filename, str, a);
	if (!str)
		return ;
	info->width = ft_strlen(str) - 1;
	str = delete_newline(str);
	info->map = ft_strdup(str);
	while (str)
	{
		info->height++;
		str = get_next_line(fd);
		if (!str)
			break ;
		str = delete_newline(str);
		info->map = ft_strjoin(info->map, str);
	}
	close(fd);
}

void	check_rectangle(t_info *info)
{
	if (info->height * info->width != ft_strlen(info->map))
		print_error("");
}

void	check_wall(t_info *info)
{
	int	i;
	int	map_len;

	i = 0;
	map_len = ft_strlen(info->map);
	while (i < map_len)
	{
		if (info->map[i] < info->width || info->map[i] >= map_len - info->width
		|| map_len % info->width == 0 || map_len % info->width == info->width - 1)
		{
			if (info->map[i] != 1)
				print_error("");
		}
		i++;
	}
}

void	check_element(t_info *info)
{
	int	i;

	i = 0;
	while (i++ < ft_strlen(info->map))
	{
		if (info->map[i] == 'E')
			info->exit++;
		else if (info->map[i] == 'C')
			info->collect++;
		else if (info->map[i] == 'P')
		{
			if (info->player > 1)
				info->map[i] = '0';
			else
				info->player = i;
		}
	}
	if (info->exit == 0)
		print_error("");
	else if (info->collect == 0)
		print_error("");
	else if (info->player == 0)
		print_error("");
}

// void	check_map(char *map_arr, t_info *info)
// {
// 	char	*index;

// 	if (check_map_wall(map_arr))
// 	{
// 		perror("map_wall error");
// 		exit(1);
// 	}
// 	else if (info->exit)
// 	{
// 		perror("There is no exit");
// 		exit(1);
// 	}
// 	else if (info->collect)
// 	{
// 		perror("There is no collect");
// 		exit(1);
// 	}
// 	else if (info->player)
// 	{
// 		perror("There is no player");
// 		exit(1);
// 	}
// }

// char *map(char *map_arr, char *map_name)
// {
// 	int ret;

// 	// check_map_name(map_name);
// 	map_arr = get_map(map_arr, map_name);
// 	check_map(map_arr);
// 	// if (ret)
// 	// 	print_error(ret);
// 	return (map_arr);
// }