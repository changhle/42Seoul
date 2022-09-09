/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhle <changhle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 19:41:55 by changhle          #+#    #+#             */
/*   Updated: 2022/09/09 17:52:39 by changhle         ###   ########.fr       */
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

static void	wasd_press(t_info *info, int move)
{
	char	*str;

	if (info->map[info->player - move] != '1')
	{
		if (info->map[info->player - move] == 'C')
			info->collect--;
		if (!(info->map[info->player - move] == 'E' && info->collect != 0))
		{
			info->walk++;
			// printf("움직인 횟수 : %d\n", info->walk);
			if (info->map[info->player - move] == 'E' && info->collect == 0)
				exit_game("game clear!");
			info->map[info->player - move] = 'P';
			info->map[info->player] = '0';
			info->player -= move;
			// print_move_image(info, info->ptr, info->player, move);
			put_image(info, info->ptr, (info->player + move) % info->width,
				(info->player + move) / info->width);
			put_image(info, info->ptr, 0, 0);
			// print_image(info, info->ptr);
			str = ft_itoa(info->walk);
			mlx_string_put(info->ptr->mlx, info->ptr->mlx_win, 2, 14, 0xFFFFFF, "MOVE: ");
			mlx_string_put(info->ptr->mlx, info->ptr->mlx_win, 43, 14, 0xFFFFFF, str);
		}
	}
}

static void	patrol_move(t_info *info, int move)
{
	char	*str;

	
	if (info->map[info->patrol - move] == '0'
		|| info->map[info->patrol - move] == 'P')
	{
		info->map[info->patrol - move] = 'M';
		// if (info->map[info->patrol] == 'M')
		info->map[info->patrol] = '0';
		info->patrol -= move;
			put_image(info, info->ptr, (info->patrol + move) % info->width,
				(info->patrol + move) / info->width);
		// print_move_image(info, info->ptr, info->patrol, move);
		// print_image(info, info->ptr);
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
		wasd_press(info, info->width);
		patrol_move(info, -info->width);
	}
	else if (keycode == KEY_A)
	{	
		wasd_press(info, 1);
		patrol_move(info, -1);
	}
	else if (keycode == KEY_S)
	{
		wasd_press(info, -info->width);
		patrol_move(info, info->width);
	}
	else if (keycode == KEY_D)
	{
		wasd_press(info, -1);
		patrol_move(info, 1);
	}
	return (0);
}
