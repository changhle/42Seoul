/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhle <changhle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 19:03:56 by changhle          #+#    #+#             */
/*   Updated: 2022/08/02 16:43:30 by changhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx/mlx.h"
// #include "minilibx_opengl_20191021/mlx.h"

#define KEY_ESC 53
#define KEY_W 13
#define KEY_A 0
#define KEY_S 1
#define KEY_D 2

// char	*check_map(char **map, t_param *param)
// {
// 	int	fd;

// 	fd = open("./maps/map1.ber", O_RDONLY);
// 	map = (char **)malloc(sizeof(char *) * 6);
// 	while (param->hight < 5)
// 	{
// 		if (param->hight == 0 || param->hight == 4)
// 		{
// 			map[param->hight] = get_next_line(fd);
// 			if (param->width == 0)
// 				param->width = ft_strlen(map[param->hight]) - 1;
// 			else if (param->width != ft_strlen(map[param->hight] - 1))
// 				exit(0);
// 			while (i < param->width)
// 			{
// 				if (map[param->width][i] != 1)
// 					exit(0);
// 			}
// 		}
// 		else if (param->hight > 0 && param->hight < 4)
// 		{
// 			map[param->hight] = get_next_line(fd);
// 			if (param->width != ft_strlen(map[param->hight] - 1))
// 				error;
// 			if (map[0] == 0 || map[param->hight] == 0)
// 				exit(0);
// 		}
// 	}
// 	if (ft_strlen(get_next_line(fd)) > 0)
// 		exit(0);
// }
static void	init_info(t_info *info)
{
	info->height = 0;
	info->width = 0;
	info->exit = 0;
	info->collect = 0;
	info->player = 0;
	info->walk = 0;
}

int	main(int argc, char **argv)
{
	t_info	info;
	t_ptr	ptr;
	t_game	game;

	init_info(&info);
	parse(argc, argv, info);
	xpm_to_image(&info, &ptr);
	game.info = &info;
	game.ptr = &ptr;
	mlx_key_hook(ptr.mlx_win, key_press, &game);
	mlx_hook(ptr.mlx_win, 17, &exit, &0);
	mlx_loop(ptr.mlx);
	return (0);
}
