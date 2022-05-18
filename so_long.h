#ifndef SO_LONG_H
# define SO_LONG_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

typedef struct	s_info
{
	char	*map;
	int		height;
	int		width;
}	t_info;

void	check_filename(char *filename);
void	get_map(char *filename, t_info *info);
void	check_rectangle(t_info *info);
void	check_wall(t_info *info);
char	*map(char *map_arr, char *map_name);

#endif