/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhle <changhle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 19:41:42 by changhle          #+#    #+#             */
/*   Updated: 2022/09/10 04:44:29 by changhle         ###   ########.fr       */
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
	// printf("-----2-------\n");
	if (info->map[loc] == 'E')
		mlx_put_image_to_window(ptr->mlx, ptr->mlx_win,
			ptr->exit_ptr[0], x * 64, y * 64);
	// printf("-----3-------\n");
	printf("%c\n", info->map[loc]);
	if (info->map[loc] == 'C')
		mlx_put_image_to_window(ptr->mlx, ptr->mlx_win,
			ptr->collect_ptr[0], x * 64, y * 64);
	if (info->map[loc] == 'P')
		mlx_put_image_to_window(ptr->mlx, ptr->mlx_win,
			ptr->player00_ptr, x * 64, y * 64);
	if (info->map[loc] == 'M')
		mlx_put_image_to_window(ptr->mlx, ptr->mlx_win,
			ptr->patrol00_ptr, x * 64, y * 64);
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
		printf("%d\n", y);
		y++;
	}
}

int	print_sprite_image(t_sprite *sprite)
{
	t_info	*info;
	t_ptr	*ptr;
	int	i;

	info = sprite->info;
	ptr = sprite->ptr;
	printf("==============\n");
	i = 0;
	// while (i < 4)
	// {
	printf("%d\n", i);
	printf("%d\n", sprite->fps);
	if (sprite->fps == 0)
	{
		mlx_put_image_to_window(ptr->mlx, ptr->mlx_win,
			ptr->tile_ptr, (info->player % info->width) * 64,
			(info->player / info->width) * 64);
		mlx_put_image_to_window(ptr->mlx, ptr->mlx_win,
			ptr->tile_ptr, (info->patrol % info->width) * 64,
			(info->patrol / info->width) * 64);
		mlx_put_image_to_window(ptr->mlx, ptr->mlx_win,
			ptr->player00_ptr, (info->player % info->width) * 64,
			(info->player / info->width) * 64);
		mlx_put_image_to_window(ptr->mlx, ptr->mlx_win,
			ptr->patrol00_ptr, (info->patrol % info->width) * 64,
			(info->patrol / info->width) * 64);
	}
	else if (sprite->fps == 2000)
	{
		mlx_put_image_to_window(ptr->mlx, ptr->mlx_win,
			ptr->tile_ptr, (info->player % info->width) * 64,
			(info->player / info->width) * 64);
		mlx_put_image_to_window(ptr->mlx, ptr->mlx_win,
			ptr->tile_ptr, (info->patrol % info->width) * 64,
			(info->patrol / info->width) * 64);
		mlx_put_image_to_window(ptr->mlx, ptr->mlx_win,
			ptr->player01_ptr, (info->player % info->width) * 64,
			(info->player / info->width) * 64);
		mlx_put_image_to_window(ptr->mlx, ptr->mlx_win,
			ptr->patrol01_ptr, (info->patrol % info->width) * 64,
			(info->patrol / info->width) * 64);
	}
	else if (sprite->fps == 4000)
	{
		mlx_put_image_to_window(ptr->mlx, ptr->mlx_win,
			ptr->tile_ptr, (info->player % info->width) * 64,
			(info->player / info->width) * 64);
		mlx_put_image_to_window(ptr->mlx, ptr->mlx_win,
			ptr->tile_ptr, (info->patrol % info->width) * 64,
			(info->patrol / info->width) * 64);
		mlx_put_image_to_window(ptr->mlx, ptr->mlx_win,
			ptr->player02_ptr, (info->player % info->width) * 64,
			(info->player / info->width) * 64);
		mlx_put_image_to_window(ptr->mlx, ptr->mlx_win,
			ptr->patrol02_ptr, (info->patrol % info->width) * 64,
			(info->patrol / info->width) * 64);
	}
	else if (sprite->fps == 6000)
	{
		mlx_put_image_to_window(ptr->mlx, ptr->mlx_win,
			ptr->tile_ptr, (info->player % info->width) * 64,
			(info->player / info->width) * 64);
		mlx_put_image_to_window(ptr->mlx, ptr->mlx_win,
			ptr->tile_ptr, (info->patrol % info->width) * 64,
			(info->patrol / info->width) * 64);
		mlx_put_image_to_window(ptr->mlx, ptr->mlx_win,
			ptr->player03_ptr, (info->player % info->width) * 64,
			(info->player / info->width) * 64);
		mlx_put_image_to_window(ptr->mlx, ptr->mlx_win,
			ptr->patrol03_ptr, (info->patrol % info->width) * 64,
			(info->patrol / info->width) * 64);
	}
	sprite->fps++;
	if (sprite->fps > 8000)
		sprite->fps = 0;

	// mlx_put_image_to_window(ptr->mlx, ptr->mlx_win,
	// 	ptr->tile_ptr, (info->player % info->width) * 64,
	// 	(info->player / info->width) * 64);
	// mlx_put_image_to_window(ptr->mlx, ptr->mlx_win,
	// 	ptr->player00_ptr, (info->player % info->width) * 64,
	// 	(info->player / info->width) * 64);
	printf("=====%d====\n", i);
	printf("%d\n", info->patrol);
		// i++;
	// }
	printf("==%d==\n", i);
	return (0);
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

void	xpm_to_player_image(t_ptr *ptr, int width, int height)
{
	ptr->player01_ptr = mlx_xpm_file_to_image(ptr->mlx,
			"../images/player00.xpm", &width, &height);
	ptr->player01_ptr = mlx_xpm_file_to_image(ptr->mlx,
			"../images/player01.xpm", &width, &height);
	ptr->player02_ptr = mlx_xpm_file_to_image(ptr->mlx,
			"../images/player02.xpm", &width, &height);
	ptr->player03_ptr = mlx_xpm_file_to_image(ptr->mlx,
			"../images/player03.xpm", &width, &height);
}

void	xpm_to_patrol_image(t_ptr *ptr, int width, int height)
{
	ptr->patrol00_ptr = mlx_xpm_file_to_image(ptr->mlx,
			"../images/patrol00.xpm", &width, &height);
	ptr->patrol01_ptr = mlx_xpm_file_to_image(ptr->mlx,
			"../images/patrol01.xpm", &width, &height);
	ptr->patrol02_ptr = mlx_xpm_file_to_image(ptr->mlx,
			"../images/patrol02.xpm", &width, &height);
	ptr->patrol03_ptr = mlx_xpm_file_to_image(ptr->mlx,
			"../images/patrol04.xpm", &width, &height);
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
	ptr->exit_ptr[0] = mlx_xpm_file_to_image(ptr->mlx,
			"../images/exit.xpm", &width, &height);
	ptr->collect_ptr[0] = mlx_xpm_file_to_image(ptr->mlx,
			"../images/collect.xpm", &width, &height);
	ptr->player00_ptr = mlx_xpm_file_to_image(ptr->mlx,
			"../images/player00.xpm", &width, &height);
	ptr->patrol00_ptr = mlx_xpm_file_to_image(ptr->mlx,
			"../images/patrol00.xpm", &width, &height);
	xpm_to_player_image(ptr, width, height);
	xpm_to_patrol_image(ptr, width, height);
	printf("1---------\n");
	info->ptr = ptr;
	printf("2---------\n");
	print_image(info, ptr);
	printf("3---------\n");
}
