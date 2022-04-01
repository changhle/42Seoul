#include "so_long.h"
#include <mlx.h>

#define KEY_W 13
#define KEY_A 0
#define KEY_S 1
#define KEY_D 2
#define KEY_ESC 53

int	key_press(int keycode, t_param *param)
{
	if (keycode == KEY_W)
		param->y++;
	else if (keycode == KEY_A)
		param->x--;
	else if (keycode == KEY_S)
		param->y--;
	else if (keycode == KEY_D)
		param->x++;
	else if (keycode == KEY_ESC)
		exit(0);
	printf("(x, y) : (%d, %d)\n", param->x, param->y);
	return (0);
}

int	main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	int		width;
	int		hight;
	int		x, y;
	int		arr[10][10] = {{1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1, 1, 1, 1, 1} };
	t_param	param;

	width = 1000;
	hight = 50;
	param.x = 0;
	param.y = 0;
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 64*10, 64*10, "so_long");
	img_ptr = mlx_xpm_file_to_image(mlx_ptr, "./images/tile00.xpm", &width, &hight);
	x = 0;
	while (x < 10)
	{
		y = 0;
		while (y < 10)
		{
			mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, x * 64, y * 64);
			y++;
		}
		x++;
	}
	mlx_key_hook(win_ptr, &key_press, &param);
	mlx_loop(mlx_ptr);
	return (0);
}