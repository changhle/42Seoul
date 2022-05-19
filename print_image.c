#include "so_long.h"
#include "./mlx/mlx.h"

void	print_image(t_info *info, t_ptr *ptr)
{
	int	x;
	int	y;

	y = 0;
	while (y < info->height)
	{
		x = 0;
		while (x < info->width)
		{
			if (info->map[y * info->width + x] == '1')
				mlx_put_image_to_window(ptr->mlx, ptr->mlx_win, ptr->wall_ptr, x * 64, y * 64);
			else if (info->map[y * info->width + x] == '0')
				mlx_put_image_to_window(ptr->mlx, ptr->mlx_win, ptr->tile_ptr, x * 64, y * 64);
			else if (info->map[y * info->width + x] == 'E')
			{
				mlx_put_image_to_window(ptr->mlx, ptr->mlx_win, ptr->tile_ptr, x * 64, y * 64);
				mlx_put_image_to_window(ptr->mlx, ptr->mlx_win, ptr->exit_ptr, x * 64, y * 64);
			}
			else if (info->map[y * info->width + x] == 'C')
			{
				mlx_put_image_to_window(ptr->mlx, ptr->mlx_win, ptr->tile_ptr, x * 64, y * 64);
				mlx_put_image_to_window(ptr->mlx, ptr->mlx_win, ptr->collect_ptr, x * 64, y * 64);
			}
			else if (info->map[y * info->width + x] == 'P')
			{
				mlx_put_image_to_window(ptr->mlx, ptr->mlx_win, ptr->tile_ptr, x * 64, y * 64);
				mlx_put_image_to_window(ptr->mlx, ptr->mlx_win, ptr->player_ptr, x * 64, y * 64);
			}
			x++;
		}
		y++;
	}
	// while (i < ft_strlen(info->map))
	// {
	// 	if (info->map[i] == 1)
	// 		mlx_put_image_to_window(ptr->mlx, ptr->mlx_win, ptr->wall_ptr, i / info->width * 64, i % info->width)
	// }
}