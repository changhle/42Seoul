/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhle <changhle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 19:41:22 by changhle          #+#    #+#             */
/*   Updated: 2022/09/10 07:36:46 by changhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../libft/libft.h"
#include "../mlx/mlx.h"

int	main(int argc, char **argv)
{
	t_info		info;
	t_ptr		ptr;
	t_sprite	sprite;

	ft_memset(&info, 0, sizeof(t_info));
	parse(argc, argv, &info);
	xpm_to_image(&info, &ptr);
	mlx_string_put(ptr.mlx, ptr.mlx_win, 2, 14, 0xFFFFFF, "MOVE: 0");
	mlx_key_hook(ptr.mlx_win, key_press, &info);
	mlx_hook(ptr.mlx_win, 17, 0, &exit_game, "Press red button!");
	sprite.info = &info;
	sprite.ptr = &ptr;
	sprite.count = 0;
	mlx_loop_hook(ptr.mlx, &print_sprite_image, &sprite);
	mlx_loop(ptr.mlx);
	return (0);
}
