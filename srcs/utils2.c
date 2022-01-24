/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khelegbe <khelegbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 16:14:20 by khelegbe          #+#    #+#             */
/*   Updated: 2022/01/21 16:47:38 by khelegbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_arraylen(char **array)
{
	int	i;

	i = 0;
	while (array && array[i])
		i++;
	return (i);
}

int	checking_file(char *arg)
{
	int		fd2;
	void	*readed;
	int		check_file;

	fd2 = open_file(arg);
	readed = NULL;
	check_file = read(fd2, &readed, 10);
	if (check_file == 0 || check_file == -1)
	{
		close(fd2);
		return (1);
	}
	close(fd2);
	return (0);
}

void	get_player_pos(char **map, t_coord *pos)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				pos->x = j;
				pos->y = i;
			}
			j++;
		}
		i++;
		j = 0;
	}
}
