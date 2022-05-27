#include "so_long.h"
#include "./libft/libft.h"
#include "./mlx/mlx.h"
#include "./ft_printf/ft_printf.h"
#define KEY_ESC 53
#define KEY_W 13
#define KEY_A 0
#define KEY_S 1
#define KEY_D 2

void	exit_game(t_game *game)
{
	exit(0);
}

void	w_press(t_game *game)
{
	t_info 	*info;
	
	info = game->info;
	if (info->map[info->player - info->width] == 'C')
		info->collect--;
	else if (info->map[info->player - info->width] == 'E' && info->collect == 0)
	{
		info->map[info->player] = '0';
		info->map[info->player - info->width] = 'P';
		info->walk++;
		ft_printf("움직인 횟수 : %d\ngame clear!!\n", info->walk);
		// ft_putnbr_fd(info->walk, 1);
		// ft_putstr_fd("game clear!!", 1);
		exit_game(game);
	}
	if (info->map[info->player - info->width] != '1' && info->map[info->player - info->width] != 'E')
	{
		info->map[info->player] = '0';
		info->map[info->player - info->width] = 'P';
		info->player -= info->width;
		info->walk++;
		ft_printf("움직인 횟수 : %d\n", info->walk);
		// ft_putnbr_fd(info->walk, 1);
		print_image(info, game->ptr);
	}
}

void	a_press(t_game *game)
{
	t_info 	*info;
	
	info = game->info;
	if (info->map[info->player - 1] == 'C')
		info->collect--;
	else if (info->map[info->player - 1] == 'E' && info->collect == 0)
	{
		info->map[info->player] = '0';
		info->map[info->player - 1] = 'P';
		info->walk++;
		ft_printf("움직인 횟수 : %d\ngame clear!!\n", info->walk);
		// ft_putnbr_fd(info->walk, 1);
		// ft_putstr_fd("game clear!!", 1);
		exit_game(game);
	}
	if (info->map[info->player - 1] != '1' && info->map[info->player - 1] != 'E')
	{
		info->map[info->player] = '0';
		info->map[info->player - 1] = 'P';
		info->player -= 1;
		info->walk++;
		ft_printf("움직인 횟수 : %d\n", info->walk);
		// ft_putnbr_fd(info->walk, 1);
		print_image(info, game->ptr);
	}
}

void	s_press(t_game *game)
{
	t_info 	*info;
	
	info = game->info;
	if (info->map[info->player + info->width] == 'C')
		info->collect--;
	else if (info->map[info->player + info->width] == 'E' && info->collect == 0)
	{
		info->map[info->player] = '0';
		info->map[info->player + info->width] = 'P';
		info->walk++;
		ft_printf("움직인 횟수 : %d\ngame clear!!\n", info->walk);
		// ft_putnbr_fd(info->walk, 1);
		// ft_putstr_fd("game clear!!", 1);
		exit_game(game);
	}
	if (info->map[info->player + info->width] != '1' && info->map[info->player + info->width] != 'E')
	{
		info->map[info->player] = '0';
		info->map[info->player + info->width] = 'P';
		info->player += info->width;
		info->walk++;
		ft_printf("움직인 횟수 : %d\n", info->walk);
		// ft_putnbr_fd(info->walk, 1);
		print_image(info, game->ptr);
	}
}

void	d_press(t_game *game)
{
	t_info 	*info;
	
	info = game->info;
	if (info->map[info->player + 1] == 'C')
		info->collect--;
	else if (info->map[info->player + 1] == 'E' && info->collect == 0)
	{
		info->map[info->player] = '0';
		info->map[info->player + 1] = 'P';
		info->walk++;
		ft_printf("움직인 횟수 : %d\ngame clear!!\n", info->walk);
		// ft_putnbr_fd(info->walk, 1);
		// ft_putstr_fd("game clear!!", 1);
		exit_game(game);
	}
	if (info->map[info->player + 1] != '1' && info->map[info->player + 1] != 'E')
	{
		info->map[info->player] = '0';
		info->map[info->player + 1] = 'P';
		info->player += 1;
		info->walk++;
		ft_printf("움직인 횟수 : %d\n", info->walk);
		// ft_putnbr_fd(info->walk, 1);
		print_image(info, game->ptr);
	}
}

int	key_press(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		exit_game(game);
	else if (keycode == KEY_W)
		w_press(game);
	else if (keycode == KEY_A)
		a_press(game);
	else if (keycode == KEY_S)
		s_press(game);
	else if (keycode == KEY_D)
		d_press(game);
	return (0);
}