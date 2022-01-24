/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khelegbe <khelegbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 17:10:49 by khelegbe          #+#    #+#             */
/*   Updated: 2022/01/24 20:23:00 by khelegbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	can_move(char **map, t_coord next_move, int consomable_left)
{
	char	next_position;

	next_position = map[next_move.y][next_move.x];
	if (next_position == '0' || next_position == 'C'
		|| (next_position == 'E' && consomable_left == 0))
		return (0);
	return (1);
}

int	change_pos(t_game *game, t_coord next_move)
{
	if (can_move(game->map, next_move, game->consomable_left) == 1)
		return (1);
	if (game->map[next_move.y][next_move.x] == 'E')
	{
		exit_game(game);
	}
	else if (game->map[next_move.y][next_move.x] == 'C')
		game->consomable_left--;
	game->map[next_move.y][next_move.x] = 'P';
	game->map[game->player_pos.y][game->player_pos.x] = '0';
	ft_putstr_fd("\r                                        ", STDOUT_FILENO);
	ft_putstr_fd("\rMove count: ", STDOUT_FILENO);
	ft_putnbr_fd(++game->move_count, STDOUT_FILENO);
	return (0);
}

void	moves(t_game *game, int direction)
{
	t_coord		player_pos;

	player_pos.x = game->player_pos.x;
	player_pos.y = game->player_pos.y;
	if (direction == KEY_UP)
		player_pos.y--;
	else if (direction == KEY_DOWN)
		player_pos.y++;
	else if (direction == KEY_LEFT)
		player_pos.x--;
	else if (direction == KEY_RIGHT)
		player_pos.x++;
	else if (direction == KEY_ESCAPE)
		exit_game(game);
	if (change_pos(game, player_pos) == 0)
	{
		game->player_pos.x = player_pos.x;
		game->player_pos.y = player_pos.y;
	}
}
