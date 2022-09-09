/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_image.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhle <changhle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 07:04:01 by changhle          #+#    #+#             */
/*   Updated: 2022/09/10 08:34:29 by changhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../mlx/mlx.h"

static void	put_tile(t_info *info, t_ptr *ptr, unsigned int x, unsigned int y)
{
	unsigned int	loc;

	loc = y * info->width + x;
	if (x == 0 && y == 0)
	{
		mlx_put_image_to_window(ptr->mlx, ptr->mlx_win,
			ptr->wall_move_ptr, x * 64, y * 64);
		return ;
	}
	if (info->map[loc] == '1')
		mlx_put_image_to_window(ptr->mlx, ptr->mlx_win,
			ptr->wall_ptr, loc % info->width * 64, loc / info->width * 64);
	if (info->map[loc] == '0' || info->map[loc] == 'E' || info->map[loc] == 'C'
		|| info->map[loc] == 'P' || info->map[loc] == 'M')
		mlx_put_image_to_window(ptr->mlx, ptr->mlx_win,
			ptr->tile_ptr, x * 64, y * 64);
}

void	put_image(t_info *info, t_ptr *ptr, unsigned int x, unsigned int y)
{
	unsigned int	loc;

	loc = y * info->width + x;
	put_tile(info, ptr, x, y);
	if (info->map[loc] == 'E' && info->collect != 0)
		mlx_put_image_to_window(ptr->mlx, ptr->mlx_win,
			ptr->exit_ptr[0], x * 64, y * 64);
	else if (info->map[loc] == 'E' && info->collect == 0)
		mlx_put_image_to_window(ptr->mlx, ptr->mlx_win,
			ptr->exit_ptr[1], x * 64, y * 64);
	if (info->map[loc] == 'C')
		mlx_put_image_to_window(ptr->mlx, ptr->mlx_win,
			ptr->collect_ptr, x * 64, y * 64);
	if (info->map[loc] == 'P')
		mlx_put_image_to_window(ptr->mlx, ptr->mlx_win,
			ptr->player_ptr[0], x * 64, y * 64);
	if (info->map[loc] == 'M')
		mlx_put_image_to_window(ptr->mlx, ptr->mlx_win,
			ptr->patrol_ptr[0], x * 64, y * 64);
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

static void	set_count(t_sprite *sprite)
{
	if (sprite->count++ > 8000)
		sprite->count = 0;
}

int	print_sprite_image(t_sprite *sprite)
{
	unsigned int	p;
	unsigned int	m;
	unsigned int	w;
	int				i;

	i = -1;
	p = sprite->info->player;
	m = sprite->info->patrol;
	w = sprite->info->width;
	if (sprite->count % 2000 == 0)
		i = sprite->count / 2000;
	if (i >= 0)
	{
		mlx_put_image_to_window(sprite->ptr->mlx, sprite->ptr->mlx_win,
			sprite->ptr->tile_ptr, (p % w) * 64, (p / w) * 64);
		mlx_put_image_to_window(sprite->ptr->mlx, sprite->ptr->mlx_win,
			sprite->ptr->tile_ptr, (m % w) * 64, (m / w) * 64);
		mlx_put_image_to_window(sprite->ptr->mlx, sprite->ptr->mlx_win,
			sprite->ptr->player_ptr[i], (p % w) * 64, (p / w) * 64);
		mlx_put_image_to_window(sprite->ptr->mlx, sprite->ptr->mlx_win,
			sprite->ptr->patrol_ptr[i], (m % w) * 64, (m / w) * 64);
	}
	set_count(sprite);
	return (0);
}
