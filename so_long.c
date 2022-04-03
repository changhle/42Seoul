#include "so_long.h"
#include <mlx.h>
#include <fcntl.h>

#define KEY_W 13
#define KEY_A 0
#define KEY_S 1
#define KEY_D 2
#define KEY_ESC 53

char	*check_map(char **map, t_param *param)
{
	int	fd;

	fd = open("./maps/map1.ber", O_RDONLY);
	map = (char **)malloc(sizeof(char *) * 6);
	while (param->hight < 5)
	{
		if (param->hight == 0 || param->hight == 4)
		{
			map[param->hight] = get_next_line(fd);
			if (param->width == 0)
				param->width = ft_strlen(map[param->hight]) - 1;
			else if (param->width != ft_strlen(map[param->hight] - 1))
				exit(0);
			while (i < param->width)
			{
				if (map[param->width][i] != 1)
					exit(0);
			}
		}
		else if (param->hight > 0 && param->hight < 4)
		{
			map[param->hight] = get_next_line(fd);
			if (param->width != ft_strlen(map[param->hight] - 1))
				error;
			if (map[0] == 0 || map[param->hight] == 0)
				exit(0);
		}
	}
	if (ft_strlen(get_next_line(fd)) > 0)
		exit(0);
}

int	main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	int		width;
	int		hight;
	int		x, y;
	char	**map;
	t_param	param;

	check_map(map, &param);
	printf("%s\n", map[0]);
	printf("%s\n", map[1]);
	printf("%s\n", map[2]);
	printf("%s\n", map[3]);
	printf("%s\n", map[4]);
	width = 1000;
	hight = 50;
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 64*10, 64*10, "so_long");
	// img_ptr = mlx_xpm_file_to_image(mlx_ptr, "./images/tile00.xpm", &width, &hight);
	// x = 0;
	// while (x < 10)
	// {
	// 	y = 0;
	// 	while (y < 10)
	// 	{
	// 		mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, x * 64, y * 64);
	// 		y++;
	// 	}
	// 	x++;
	// }
	// mlx_key_hook(win_ptr, &key_press, &param);
	mlx_loop(mlx_ptr);
	return (0);
}