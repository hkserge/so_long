/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_checkmap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khelegbe <khelegbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 16:01:56 by khelegbe          #+#    #+#             */
/*   Updated: 2022/01/21 16:12:39 by khelegbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_valid_border(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '1')
			return (print_error(MAP_NOT_CLOSED));
		i++;
	}
	return (0);
}

int	is_valid_middle(char *line, t_required *conf)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (i == 0 || i == (int)ft_strlen(line) - 1)
		{
			if (line[i] != '1')
				return (print_error(MAP_NOT_CLOSED));
		}
		else
		{
			if (ft_strchr("01CEP", line[i]) == NULL)
				return (print_error(INVALID_CHAR_MAP));
			if (line[i] == 'P')
				conf->player++;
			else if (line[i] == 'E')
				conf->exit++;
			else if (line[i] == 'C')
				conf->consomable++;
		}
		i++;
	}
	return (0);
}

int	check_rectangle(char **map)
{
	int		i;
	size_t	length;

	length = ft_strlen(map[0]);
	i = 0;
	while (map[i] != NULL)
	{
		if (length != ft_strlen(map[i]))
			return (print_error(MAP_NOT_RECTANGLE));
		i++;
	}
	if (i < 2)
		return (print_error(MAP_IS_ONE_LINE));
	return (0);
}

int	check_walls(char **map, t_required *conf)
{
	int	i;
	int	len;

	i = 0;
	len = ft_arraylen(map);
	while (map[i])
	{
		if (i == 0 || i == len - 1)
		{
			if (is_valid_border(map[i]) == 1)
				return (1);
		}
		else
		{
			if (is_valid_middle(map[i], conf) == 1)
				return (1);
		}
		i++;
	}
	return (0);
}

int	verify_map(t_game *game)
{
	t_required	tmp;

	tmp.player = 0;
	tmp.consomable = 0;
	tmp.exit = 0;
	if (check_rectangle(game->map) == 1)
		return (1);
	if (check_walls(game->map, &tmp) == 1)
		return (1);
	if (tmp.player != 1 || tmp.exit < 1 || tmp.consomable < 1)
	{
		print_error(BAD_ITEMS_IN_FILE);
		return (1);
	}
	game->consomable_left = tmp.consomable;
	get_player_pos(game->map, &(game->player_pos));
	return (0);
}
