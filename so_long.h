/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhle <changhle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 19:42:19 by changhle          #+#    #+#             */
/*   Updated: 2022/08/15 19:42:22 by changhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_info
{
	char	*map;
	int		height;
	int		width;
	int		exit;
	int		collect;
	int		player;
	int		walk;
}	t_info;

typedef struct s_ptr
{
	void	*mlx;
	void	*mlx_win;
	void	*wall_ptr;
	void	*tile_ptr;
	void	*exit_ptr;
	void	*collect_ptr;
	void	*player_ptr;
}	t_ptr;

typedef struct s_game
{
	t_info	*info;
	t_ptr	*ptr;
}	t_game;

void	parse(int argc, char **argv, t_info *info);
void	print_error(char *str);
char	*delete_newline(char *str);
void	xpm_to_image(t_info *info, t_ptr *ptr);
void	print_image(t_info *info, t_ptr *ptr);
int		key_press(int keycode, t_game *game);
int		exit_game(t_game *game);

// void	check_filename(char *filename);
// void	get_map(char *filename, t_info *info);
// void	check_rectangle(t_info *info);
// void	check_wall(t_info *info);
// void	check_element(t_info *info);
// char	*map(char *map_arr, char *map_name);
// void	print_image(t_info *info, t_ptr *ptr);
// int		key_press(int keycode, t_game *game);

#endif