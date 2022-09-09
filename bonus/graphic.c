/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhle <changhle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 19:41:42 by changhle          #+#    #+#             */
/*   Updated: 2022/09/09 19:41:27 by changhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../mlx/mlx.h"

void	put_image(t_info *info, t_ptr *ptr, unsigned int x, unsigned int y)
{
	unsigned int	loc;

	loc = y * info->width + x;
	if (x == 0 && y == 0)
	{
		mlx_put_image_to_window(ptr->mlx, ptr->mlx_win,
			ptr->wall_1_ptr, x * 64, y * 64);
		return ;
	}
	if (info->map[loc] == '1')
		mlx_put_image_to_window(ptr->mlx, ptr->mlx_win,
			ptr->wall_ptr, x * 64, y * 64);
	else if (info->map[loc] == '0' || info->map[loc] == 'E'
		|| info->map[loc] == 'C' || info->map[loc] == 'P'
		|| info->map[loc] == 'M')
		mlx_put_image_to_window(ptr->mlx, ptr->mlx_win,
			ptr->tile_ptr, x * 64, y * 64);
	if (info->map[loc] == 'E')
		mlx_put_image_to_window(ptr->mlx, ptr->mlx_win,
			ptr->exit_ptr, x * 64, y * 64);
	if (info->map[loc] == 'C')
		mlx_put_image_to_window(ptr->mlx, ptr->mlx_win,
			ptr->collect_ptr, x * 64, y * 64);
	if (info->map[loc] == 'P')
		mlx_put_image_to_window(ptr->mlx, ptr->mlx_win,
			ptr->player_ptr, x * 64, y * 64);
	if (info->map[loc] == 'M')
		mlx_put_image_to_window(ptr->mlx, ptr->mlx_win,
			ptr->patrol_ptr, x * 64, y * 64);
}

void	print_image(t_info *info, t_ptr *ptr)
{
	unsigned int	x;
	unsigned int	y;

	y = 0;
	while (y < info->height)
	{
		x = 0;
		while (x < info->width)
		{
			put_image(info, ptr, x, y);
			x++;
		}
		y++;
	}
}

void	print_sprite_image(t_sprite *sprite)
{
	t_info	*info;
	t_ptr	*ptr;
	int	i;

	info = sprite->info;
	ptr = sprite->ptr;
	i = 0;
	while (i < 6)
	{
		mlx_put_image_to_window(ptr->mlx, ptr->mlx_win,
			ptr->player_ptr[i], (info->player % info->width) * 64,
			(info->player / info->width) * 64);
		mlx_put_image_to_window(ptr->mlx, ptr->mlx_win,
			ptr->patrol_ptr[i], (info->patrol % info->width) * 64,
			(info->patrol / info->width) * 64);
		i++;
	}
}

void	print_coordinate_image(t_info *info, t_ptr *ptr, unsigned int loc)
{
	int	x;
	int	y;

	x = loc % info->width;
	y = loc / info->width;
	put_image(info, ptr, x, y);
}

void	print_move_image(t_info *info, t_ptr *ptr,
			unsigned int target, unsigned int move)
{
	put_image(info, ptr, (target + move) % info->width,
		(target + move) / info->width);
	put_image(info, ptr, target % info->width,
		target / info->width);
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
			"../images/wall.xpm", &width, &height);
	ptr->wall_1_ptr = mlx_xpm_file_to_image(ptr->mlx,
			"../images/wall_1.xpm", &width, &height);
	ptr->tile_ptr = mlx_xpm_file_to_image(ptr->mlx,
			"../images/tile.xpm", &width, &height);
	ptr->exit_ptr = mlx_xpm_file_to_image(ptr->mlx,
			"../images/exit.xpm", &width, &height);
	xpm_to_collect_image(ptr, width, height);
	xpm_to_player_image(ptr, width, height);
	xpm_to_patrol_image(ptr, width, height);
	info->ptr = ptr;
	print_image(info, ptr);
}

void	xpm_to_collect_image(t_ptr *ptr, int width, int height)
{
	ptr->collect_ptr[0] = mlx_xpm_file_to_image(ptr->mlx,
			"../images/collect00.xpm", &width, &height);
	ptr->collect_ptr[1] = mlx_xpm_file_to_image(ptr->mlx,
			"../images/collect01.xpm", &width, &height);
	ptr->collect_ptr[2] = mlx_xpm_file_to_image(ptr->mlx,
			"../images/collect02.xpm", &width, &height);
	ptr->collect_ptr[3] = mlx_xpm_file_to_image(ptr->mlx,
			"../images/collect03.xpm", &width, &height);
	ptr->collect_ptr[4] = mlx_xpm_file_to_image(ptr->mlx,
			"../images/collect04.xpm", &width, &height);
	ptr->collect_ptr[5] = mlx_xpm_file_to_image(ptr->mlx,
			"../images/collect05.xpm", &width, &height);
}

void	xpm_to_player_image(t_ptr *ptr, int width, int height)
{
	ptr->player_ptr[0] = mlx_xpm_file_to_image(ptr->mlx,
			"../images/player00.xpm", &width, &height);
	ptr->player_ptr[1] = mlx_xpm_file_to_image(ptr->mlx,
			"../images/player01.xpm", &width, &height);
	ptr->player_ptr[2] = mlx_xpm_file_to_image(ptr->mlx,
			"../images/player02.xpm", &width, &height);
	ptr->player_ptr[3] = mlx_xpm_file_to_image(ptr->mlx,
			"../images/player03.xpm", &width, &height);
	ptr->player_ptr[4] = mlx_xpm_file_to_image(ptr->mlx,
			"../images/player04.xpm", &width, &height);
	ptr->player_ptr[5] = mlx_xpm_file_to_image(ptr->mlx,
			"../images/player05.xpm", &width, &height);
}

void	xpm_to_patrol_image(t_ptr *ptr, int width, int height)
{
	ptr->patrol_ptr[0] = mlx_xpm_file_to_image(ptr->mlx,
			"../images/patrol00.xpm", &width, &height);
	ptr->patrol_ptr[1] = mlx_xpm_file_to_image(ptr->mlx,
			"../images/patrol01.xpm", &width, &height);
	ptr->patrol_ptr[2] = mlx_xpm_file_to_image(ptr->mlx,
			"../images/patrol02.xpm", &width, &height);
	ptr->patrol_ptr[3] = mlx_xpm_file_to_image(ptr->mlx,
			"../images/patrol03.xpm", &width, &height);
	ptr->patrol_ptr[4] = mlx_xpm_file_to_image(ptr->mlx,
			"../images/patrol04.xpm", &width, &height);
	ptr->patrol_ptr[5] = mlx_xpm_file_to_image(ptr->mlx,
			"../images/patrol05.xpm", &width, &height);
}
