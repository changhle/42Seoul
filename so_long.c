#include "so_long.h"
#include "mlx/mlx.h"
// #include "minilibx_opengl_20191021/mlx.h"

#define KEY_W 13
#define KEY_A 0
#define KEY_S 1
#define KEY_D 2
#define KEY_ESC 53

// char	*check_map(char **map, t_param *param)
// {
// 	int	fd;

// 	fd = open("./maps/map1.ber", O_RDONLY);
// 	map = (char **)malloc(sizeof(char *) * 6);
// 	while (param->hight < 5)
// 	{
// 		if (param->hight == 0 || param->hight == 4)
// 		{
// 			map[param->hight] = get_next_line(fd);
// 			if (param->width == 0)
// 				param->width = ft_strlen(map[param->hight]) - 1;
// 			else if (param->width != ft_strlen(map[param->hight] - 1))
// 				exit(0);
// 			while (i < param->width)
// 			{
// 				if (map[param->width][i] != 1)
// 					exit(0);
// 			}
// 		}
// 		else if (param->hight > 0 && param->hight < 4)
// 		{
// 			map[param->hight] = get_next_line(fd);
// 			if (param->width != ft_strlen(map[param->hight] - 1))
// 				error;
// 			if (map[0] == 0 || map[param->hight] == 0)
// 				exit(0);
// 		}
// 	}
// 	if (ft_strlen(get_next_line(fd)) > 0)
// 		exit(0);
// }

int main(int argc, char **argv)
{
	// void	*mlx_ptr;
	// void	*win_ptr;
	// void	*img_ptr;
	// int		width;
	// int		hight;
	// int		x, y;
	// char *map_arr;
	// // t_param	param;
	t_info	info;
	void	*mlx;
	void	*mlx_win;

	check_filename(argv[1]);
	printf("%s\n", argv[1]);
	get_map(argv[1], &info);
	check_rectangle(&info);
	check_wall(&info);
	// check_element(&info);

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, info.width * 64, info.height * 64, "so_long");
	mlx_loop(mlx);
	// // printf("%s\n", argv[1]);
	// map_arr = map(map_arr, argv[1]);
	// while (*map_arr)
	// {
	// 	write(1, map_arr, 1);
	// 	map_arr++;
	// }
	printf("%s\n", info.map);

	// check_map(map, &param);
	// printf("%s\n", map[0]);
	// printf("%s\n", map[1]);
	// printf("%s\n", map[2]);
	// printf("%s\n", map[3]);
	// printf("%s\n", map[4]);
	// width = 1000;
	// hight = 50;
	// mlx_ptr = mlx_init();
	// win_ptr = mlx_new_window(mlx_ptr, 64*10, 64*10, "so_long");
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
	// mlx_loop(mlx_ptr);
	return (0);
}