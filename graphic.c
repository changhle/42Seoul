/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_image.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhle <changhle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 19:05:35 by changhle          #+#    #+#             */
/*   Updated: 2022/08/02 16:43:39 by changhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "./mlx/mlx.h"

static void	put_image_1_0_e(t_info *info, t_ptr *ptr, int x, int y)
{
	if (info->map[y * info->width + x] == '1')
		mlx_put_image_to_window(ptr->mlx, ptr->mlx_win,
			ptr->wall_ptr, x * 64, y * 64);
	else if (info->map[y * info->width + x] == '0')
		mlx_put_image_to_window(ptr->mlx, ptr->mlx_win,
			ptr->tile_ptr, x * 64, y * 64);
	else if (info->map[y * info->width + x] == 'E')
		mlx_put_image_to_window(ptr->mlx, ptr->mlx_win,
			ptr->exit_ptr, x * 64, y * 64);
}

static void	put_image_c_p(t_info *info, t_ptr *ptr, int x, int y)
{
	if (info->map[y * info->width + x] == 'C')
	{
		mlx_put_image_to_window(ptr->mlx, ptr->mlx_win,
			ptr->tile_ptr, x * 64, y * 64);
		mlx_put_image_to_window(ptr->mlx, ptr->mlx_win,
			ptr->collect_ptr, x * 64, y * 64);
	}
	else if (info->map[y * info->width + x] == 'P')
	{
		mlx_put_image_to_window(ptr->mlx, ptr->mlx_win,
			ptr->tile_ptr, x * 64, y * 64);
		mlx_put_image_to_window(ptr->mlx, ptr->mlx_win,
			ptr->player_ptr, x * 64, y * 64);
	}
}

void	print_image(t_info *info, t_ptr *ptr)
{
	int	x;
	int	y;

	y = 0;
	while (y < info->height)
	{
		x = 0;
		while (x < info->width)
		{
			put_image_1_0_e(info, ptr, x, y);
			put_image_c_p(info, ptr, x, y);
			x++;
		}
		y++;
	}
}

void	xpm_to_image(t_info *info, t_ptr *ptr)
{
	int		width;
	int		hight;

	width = 64;
	height = 64;
	ptr->mlx = mlx_init();
	ptr->mlx_win = mlx_new_window(ptr->mlx, info->width * width,
			info->height * height, "so_long");
	ptr->wall_ptr = mlx_xpm_file_to_image(ptr->mlx,
			"./images/tile01.xpm", &width, &height);
	ptr->tile_ptr = mlx_xpm_file_to_image(ptr->mlx,
			"./images/tile00.xpm", &width, &height);
	ptr->exit_ptr = mlx_xpm_file_to_image(ptr->mlx,
			"./images/stone.xpm", &width, &height);
	ptr->collect_ptr = mlx_xpm_file_to_image(ptr->mlx,
			"./images/ball.xpm", &width, &height);
	ptr->player_ptr = mlx_xpm_file_to_image(ptr->mlx,
			"./images/player_S00.xpm", &width, &height);
	print_image(info, ptr);
}