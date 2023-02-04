/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhle <changhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 09:13:06 by ljeongin          #+#    #+#             */
/*   Updated: 2023/02/04 17:01:27 by changhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "map.h"
#include "parse.h"

#include "libft.h"
#include <fcntl.h>

static void	init_t_map(t_game_data *game_data)
{
	game_data->map->texture = ft_malloc(1, sizeof(t_texture));
	game_data->map->texture->n = ft_malloc(1, sizeof(t_image));
	game_data->map->texture->e = ft_malloc(1, sizeof(t_image));
	game_data->map->texture->w = ft_malloc(1, sizeof(t_image));
	game_data->map->texture->s = ft_malloc(1, sizeof(t_image));
	game_data->map->texture->d = ft_malloc(1, sizeof(t_image));
	game_data->map->texture->sp = ft_malloc(1, sizeof(t_image));
	game_data->map->coord = ft_malloc(1, sizeof(t_coord));
}

static int	open_mapfile(const char *filename)
{
	const size_t	len = ft_strlen(filename);
	int				ret;

	if (len < 4 || ft_strncmp(filename + len - 4, ".cub", 5))
		error_exit_with_str("mapfile: is invalid filename");
	ret = open(filename, O_RDONLY);
	if (ret == -1)
		perror_exit((char *)filename);
	return (ret);
}

static void	init_sprite(t_game_data *game_data)
{
	int	i, j;

	game_data->sprite = ft_malloc(SPRITE_NUM, sizeof(t_sprite));
	i = 0;
	while (i < 20)
	{
		j = 0;
		while (j < 20)
		{
			game_data->sprite[i + j].x = i;
			game_data->sprite[i + j].y = j;
			j++;
		}
		i++;
	}
}

void	parse(const char *argv, t_game_data *game_data)
{
	const int	map_fd = open_mapfile(argv);

	init_t_map(game_data);
	init_texture(map_fd, game_data);
	init_map_content(map_fd, game_data->map);
	ft_close(map_fd);
	init_sprite(game_data);
	init_coord_value(game_data->map->coord);
}
