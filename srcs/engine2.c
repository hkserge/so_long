/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khelegbe <khelegbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 16:52:28 by khelegbe          #+#    #+#             */
/*   Updated: 2022/01/24 20:24:51 by khelegbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <mlx.h>

void	destroy_image(void *mlx, void *sprite)
{
	if (mlx && sprite)
		mlx_destroy_image(mlx, sprite);
}

void	put_image(t_game *game, int i, int j)
{
	if (game->map[i][j] == '1')
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->wall, j * SIZE, i * SIZE);
	else if (game->map[i][j] == 'P')
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->player, j * SIZE, i * SIZE);
	else if (game->map[i][j] == 'C')
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->consomable, j * SIZE, i * SIZE);
	else if (game->map[i][j] == 'E')
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->exit, j * SIZE, i * SIZE);
	else if (game->map[i][j] == '0')
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->floor, j * SIZE, i * SIZE);
}

int	draw_map(t_game *game)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (game->map[i])
	{
		while (game->map[i][j])
		{
			put_image(game, i, j);
			j++;
		}
		i++;
		j = 0;
	}
	return (0);
}

int	key_hook(int keycode, t_game *game)
{
	if (keycode != KEY_LEFT && keycode != KEY_DOWN
		&& keycode != KEY_UP && keycode != KEY_RIGHT
		&& keycode != KEY_ESCAPE)
		return (0);
	moves(game, keycode);
	draw_map(game);
	return (0);
}
