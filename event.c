/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhle <changhle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 19:41:55 by changhle          #+#    #+#             */
/*   Updated: 2022/08/15 19:41:57 by changhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "so_long.h"
#define KEY_ESC 53
#define KEY_W 13
#define KEY_A 0
#define KEY_S 1
#define KEY_D 2

static void	wasd_press(t_game *game, int move)
{
	t_info	*info;

	info = game->info;
	if (info->map[info->player - move] != '1')
	{
		if (info->map[info->player - move] == 'C')
			info->collect--;
		if (!(info->map[info->player - move] == 'E' && info->collect != 0))
		{
			info->walk++;
			printf("움직인 횟수 : %d\n", info->walk);
			if (info->map[info->player - move] == 'E' && info->collect == 0)
				exit_game("game clear!");
			info->map[info->player - move] = 'P';
			info->map[info->player] = '0';
			info->player -= move;
			print_image(info, game->ptr);
		}
	}
}

int	key_press(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		exit_game("Press ESC button!");
	else if (keycode == KEY_W)
		wasd_press(game, game->info->width);
	else if (keycode == KEY_A)
		wasd_press(game, 1);
	else if (keycode == KEY_S)
		wasd_press(game, -game->info->width);
	else if (keycode == KEY_D)
		wasd_press(game, -1);
	return (0);
}
