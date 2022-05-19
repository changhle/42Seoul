#include "so_long.h"
#include "./mlx/mlx.h"
#define KEY_ESC 27
#define KEY_W 87
#define KEY_A 65
#define KEY_S 83
#define KEY_D 68

exit_game(t_game *game)
{
	exit(0);
}

w_press(t_game *game)
{
	int	player_loc;
	
	player_loc = game->info->player;
	width = game->info->width;
	if (game->info->map[player_loc - width] == 'C' || game->info->map[player_loc - width] == '0')
}

a_press(t_game *game)
{}

s_press(t_game *game)
{}

d_press(t_game *game)
{}

int	*key_press(int keycode, t_game *game)
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
}