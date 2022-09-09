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
	if (info->map[loc] == 'E')
		mlx_put_image_to_window(ptr->mlx, ptr->mlx_win,
			ptr->exit_ptr[0], x * 64, y * 64);
	if (info->map[loc] == 'C')
		mlx_put_image_to_window(ptr->mlx, ptr->mlx_win,
			ptr->collect_ptr[0], x * 64, y * 64);
	// if (info->map[loc] == 'P')
	// 	mlx_put_image_to_window(ptr->mlx, ptr->mlx_win,
	// 		ptr->player00_ptr, x * 64, y * 64);
	// if (info->map[loc] == 'M')
	// 	mlx_put_image_to_window(ptr->mlx, ptr->mlx_win,
	// 		ptr->patrol00_ptr, x * 64, y * 64);
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
		y++;
	}
}

int	print_sprite_image(t_sprite *sprite)
{
	unsigned int	player;
	unsigned int	patrol;
	unsigned int	width;
	int				i;

	i = -1;
	if (sprite->fps % 2000 == 0)
		i = sprite->fps / 2000;
	if (i >= 0)
	{
		mlx_put_image_to_window(sprite->ptr->mlx, sprite->ptr->mlx_win,
			sprite->ptr->tile_ptr, (player % width) * 64, (player / width) * 64);
		mlx_put_image_to_window(sprite->ptr->mlx, sprite->ptr->mlx_win,
			sprite->ptr->tile_ptr, (patrol % width) * 64, (patrol / width) * 64);
		mlx_put_image_to_window(sprite->ptr->mlx, sprite->ptr->mlx_win,
			sprite->ptr->player_ptr[i], (player % width) * 64, (player / width) * 64);
		mlx_put_image_to_window(sprite->ptr->mlx, sprite->ptr->mlx_win,
			sprite->ptr->patrol_ptr[i], (patrol % width) * 64, (patrol / width) * 64);
	}
	if (sprite->fps++ > 8000)
		sprite->fps = 0;
	return (0);
}