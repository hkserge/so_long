/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khelegbe <khelegbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 16:15:00 by khelegbe          #+#    #+#             */
/*   Updated: 2022/01/24 19:48:21 by khelegbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <mlx.h>

int	load_sprites(t_game *game)
{
	int		img_width;
	int		img_height;

	game->player = mlx_xpm_file_to_image(game->mlx, "sprites/player.xpm",
			&img_width, &img_height);
	if (game->player == NULL)
		return (1);
	game->wall = mlx_xpm_file_to_image(game->mlx, "sprites/wall.xpm",
			&img_width, &img_height);
	if (game->wall == NULL)
		return (1);
	game->exit = mlx_xpm_file_to_image(game->mlx, "sprites/exit.xpm",
			&img_width, &img_height);
	if (game->exit == NULL)
		return (1);
	game->consomable = mlx_xpm_file_to_image(game->mlx,
			"sprites/consomable.xpm", &img_width, &img_height);
	if (game->consomable == NULL)
		return (1);
	game->floor = mlx_xpm_file_to_image(game->mlx, "sprites/floor.xpm",
			&img_width, &img_height);
	if (game->floor == NULL)
		return (1);
	return (0);
}

void	draw_count(t_game *game)
{
	char	*str;

	str = ft_itoa(game->move_count);
	mlx_string_put(game->mlx, game->mlx_win, 10, 30, TEXT_COLOR, str);
	free(str);
}

int	game_process(t_game *game)
{
	game->mlx = mlx_init();
	if (game->mlx == NULL)
		return (1);
	game->mlx_win = mlx_new_window(game->mlx, ft_strlen(game->map[0]) * SIZE,
			ft_arraylen(game->map) * SIZE, "So_Long");
	if (game->mlx_win == NULL || load_sprites(game) == 1)
		return (1);
	draw_map(game);
	mlx_hook(game->mlx_win, 33, 1L << 17, exit_game, game);
	mlx_key_hook(game->mlx_win, key_hook, game);
	mlx_loop_hook(game->mlx, draw_map, game);
	mlx_loop(game->mlx);
	return (0);
}

int	exit_game(t_game *conf)
{
	destroy_image(conf->mlx, conf->player);
	destroy_image(conf->mlx, conf->consomable);
	destroy_image(conf->mlx, conf->wall);
	destroy_image(conf->mlx, conf->exit);
	destroy_image(conf->mlx, conf->floor);
	mlx_destroy_window(conf->mlx, conf->mlx_win);
	mlx_destroy_display(conf->mlx);
	mlx_loop_end(conf->mlx);
	free(conf->mlx);
	free_game(conf);
	exit(0);
	return (0);
}

void	launch(t_game *game)
{
	game->consomable = NULL;
	game->player = NULL;
	game->wall = NULL;
	game->exit = NULL;
	game->floor = NULL;
	game->mlx_win = NULL;
	game->mlx = NULL;
	if (game_process(game) == 1)
		exit_game(game);
	return ;
}
