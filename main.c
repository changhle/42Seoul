/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhle <changhle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 19:41:22 by changhle          #+#    #+#             */
/*   Updated: 2022/08/17 16:13:16 by changhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "so_long.h"
#include "./mlx/mlx.h"

#define KEY_ESC 53
#define KEY_W 13
#define KEY_A 0
#define KEY_S 1
#define KEY_D 2

static void	init_info(t_info *info)
{
	info->map = NULL;
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

	init_info(&info);
	parse(argc, argv, &info);
	xpm_to_image(&info, &ptr);
	mlx_key_hook(ptr.mlx_win, key_press, &info);
	mlx_hook(ptr.mlx_win, 17, 0, &exit_game, "Press red button!");
	mlx_loop(ptr.mlx);
	return (0);
}
