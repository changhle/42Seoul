/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhle <changhle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 19:42:06 by changhle          #+#    #+#             */
/*   Updated: 2022/08/15 19:43:13 by changhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "so_long.h"
#include "./libft/libft.h"
#include "./get_next_line/get_next_line.h"

static void	parse_map(char *filename, t_info *info)
{
	int		fd;
	char	*str;

	fd = open(filename, O_RDONLY);
	str = get_next_line(fd);
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

static void	check_rectangle(t_info *info)
{
	if (info->height * info->width != ft_strlen(info->map))
		print_error("");
}

static void	check_wall(t_info *info)
{
	int	i;
	int	map_len;

	i = 0;
	map_len = ft_strlen(info->map);
	while (i < map_len)
	{
		if (info->map[i] < info->width
			|| info->map[i] >= map_len - info->width
			|| map_len % info->width == 0
			|| map_len % info->width == info->width - 1)
		{
			if (info->map[i] != 1)
				print_error("");
		}
		i++;
	}
}

static void	check_element(t_info *info)
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

void	parse(int argc, char **argv, t_info *info)
{
	if (argc != 2)
		print_error("");
	else if (ft_strncmp((argv[1] + ft_strlen(argv[1]) - 4), ".ber", 4))
		print_error("");
	parse_map(argv[1], info);
	check_rectangle(info);
	check_wall(info);
	check_element(info);
}
