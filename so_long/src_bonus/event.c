/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhle <changhle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 19:41:55 by changhle          #+#    #+#             */
/*   Updated: 2022/09/10 08:26:27 by changhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "so_long.h"
#include "../libft/libft.h"
#include "../mlx/mlx.h"
#define KEY_ESC 53
#define KEY_W 13
#define KEY_A 0
#define KEY_S 1
#define KEY_D 2

static void	print_move_text(t_info *info, t_ptr *ptr)
{
	char	*str;

	str = ft_itoa(info->walk);
	mlx_string_put(ptr->mlx, ptr->mlx_win, 2, 14, 0xFFFFFF, "MOVE: ");
	mlx_string_put(ptr->mlx, ptr->mlx_win, 43, 14, 0xFFFFFF, str);
}

static void	player_move(t_info *info, int move)
{
	if (info->map[info->player - move] != '1')
	{
		if (info->map[info->player - move] == 'C')
			info->collect--;
		if (info->collect == 0)
			print_image(info, info->ptr);
		if (!(info->map[info->player - move] == 'E' && info->collect != 0))
		{
			info->walk++;
			if (info->map[info->player - move] == 'E' && info->collect == 0)
				exit_game("game clear!");
			info->map[info->player - move] = 'P';
			info->map[info->player] = '0';
			info->player -= move;
			printf("움직인 횟수 : %d\n", info->walk);
			put_image(info, info->ptr, (info->player + move) % info->width,
				(info->player + move) / info->width);
			put_image(info, info->ptr, info->player % info->width,
				info->player / info->width);
			put_image(info, info->ptr, 0, 0);
		}
		print_move_text(info, info->ptr);
	}
}

static void	patrol_move(t_info *info, int move)
{
	if (info->map[info->patrol - move] == '0'
		|| info->map[info->patrol - move] == 'P')
	{
		info->map[info->patrol - move] = 'M';
		info->map[info->patrol] = '0';
		info->patrol -= move;
		put_image(info, info->ptr, info->patrol % info->width,
			info->patrol / info->width);
		put_image(info, info->ptr, (info->patrol + move) % info->width,
			(info->patrol + move) / info->width);
		if (info->player == info->patrol
			|| info->player == info->patrol + move)
			exit_game("game over...");
	}
}

int	key_press(int keycode, t_info *info)
{
	if (keycode == KEY_ESC)
		exit_game("Press ESC button!");
	else if (keycode == KEY_W)
	{
		player_move(info, info->width);
		patrol_move(info, -info->width);
	}
	else if (keycode == KEY_A)
	{	
		player_move(info, 1);
		patrol_move(info, -1);
	}
	else if (keycode == KEY_S)
	{
		player_move(info, -info->width);
		patrol_move(info, info->width);
	}
	else if (keycode == KEY_D)
	{
		player_move(info, -1);
		patrol_move(info, 1);
	}
	return (0);
}
