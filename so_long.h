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

typedef struct s_info
{
	struct s_ptr	ptr;
	char			*map;
	int				height;
	int				width;
	int				exit;
	int				collect;
	int				player;
	int				walk;
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

void	parse(int argc, char **argv, t_info *info);
void	xpm_to_image(t_info *info, t_ptr *ptr);
int		exit_game(t_game *game);
void	print_error(char *str);
char	*delete_newline(char *str);
void	print_image(t_info *info, t_ptr *ptr);
int		key_press(int keycode, t_game *game);
char	*ft_free_strjoin(char const *s1, char const *s2);

#endif