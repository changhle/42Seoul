/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhle <changhle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 19:19:35 by changhle          #+#    #+#             */
/*   Updated: 2022/06/26 19:25:01 by changhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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