/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhle <changhle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 19:41:42 by changhle          #+#    #+#             */
/*   Updated: 2022/09/10 08:16:38 by changhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../mlx/mlx.h"

static void	xpm_to_player_image(t_ptr *ptr, int width, int height)
{
	ptr->player_ptr[0] = mlx_xpm_file_to_image(ptr->mlx,
			"./images/player00.xpm", &width, &height);
	ptr->player_ptr[1] = mlx_xpm_file_to_image(ptr->mlx,
			"./images/player01.xpm", &width, &height);
	ptr->player_ptr[2] = mlx_xpm_file_to_image(ptr->mlx,
			"./images/player02.xpm", &width, &height);
	ptr->player_ptr[3] = mlx_xpm_file_to_image(ptr->mlx,
			"./images/player03.xpm", &width, &height);
}

static void	xpm_to_patrol_image(t_ptr *ptr, int width, int height)
{
	ptr->patrol_ptr[0] = mlx_xpm_file_to_image(ptr->mlx,
			"./images/patrol00.xpm", &width, &height);
	ptr->patrol_ptr[1] = mlx_xpm_file_to_image(ptr->mlx,
			"./images/patrol01.xpm", &width, &height);
	ptr->patrol_ptr[2] = mlx_xpm_file_to_image(ptr->mlx,
			"./images/patrol02.xpm", &width, &height);
	ptr->patrol_ptr[3] = mlx_xpm_file_to_image(ptr->mlx,
			"./images/patrol03.xpm", &width, &height);
}

static void	xpm_to_exit_image(t_ptr *ptr, int width, int height)
{
	ptr->exit_ptr[0] = mlx_xpm_file_to_image(ptr->mlx,
			"./images/exit00.xpm", &width, &height);
	ptr->exit_ptr[1] = mlx_xpm_file_to_image(ptr->mlx,
			"./images/exit01.xpm", &width, &height);
}

void	xpm_to_image(t_info *info, t_ptr *ptr)
{
	int		width;
	int		height;

	width = 64;
	height = 64;
	ptr->mlx = mlx_init();
	ptr->mlx_win = mlx_new_window(ptr->mlx, info->width * width,
			info->height * height, "so_long");
	ptr->wall_ptr = mlx_xpm_file_to_image(ptr->mlx,
			"./images/wall.xpm", &width, &height);
	ptr->wall_move_ptr = mlx_xpm_file_to_image(ptr->mlx,
			"./images/wall_move.xpm", &width, &height);
	ptr->tile_ptr = mlx_xpm_file_to_image(ptr->mlx,
			"./images/tile.xpm", &width, &height);
	ptr->collect_ptr = mlx_xpm_file_to_image(ptr->mlx,
			"./images/collect.xpm", &width, &height);
	xpm_to_player_image(ptr, width, height);
	xpm_to_patrol_image(ptr, width, height);
	xpm_to_exit_image(ptr, width, height);
	info->ptr = ptr;
	print_image(info, ptr);
}
