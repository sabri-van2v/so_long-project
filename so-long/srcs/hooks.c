#include "so_long.h"

int	press(int key, t_data *data)
{
	int	player;

	player = 0;
	while (data->str[player] != 'P')
		player++;
	if (key == XK_w && data->str[player - (data->settings.width / 64) - 1] != '1')
		up(data->str, data, player);
	if (key == XK_a && data->str[player - 1] != '1')
		left(data->str, data, player);
	if (key == XK_s && data->str[player + (data->settings.width / 64) + 1] != '1')
		down(data->str, data, player);
	if (key == XK_d && data->str[player + 1] != '1')
		right(data->str, data, player);
	return (0);
}

void	hooks(char *str, t_data *data)
{
	data->str = str;
	mlx_hook(data->mlx_win, KeyPress, KeyPressMask, &press, data);
}