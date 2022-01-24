/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khelegbe <khelegbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 22:43:02 by khelegbe          #+#    #+#             */
/*   Updated: 2022/01/24 21:33:33 by khelegbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_game	game;
	int		fd;

	if (argc != 2)
		return (print_error(BAD_ARGUMENTS));
	game.map = NULL;
	if (check_extension(argv[1]) == 1)
		return (1);
	fd = open_file(argv[1]);
	if (fd == -1)
		return (1);
	game.map = read_file(fd);
	close(fd);
	if (game.map == NULL)
		return (print_error(FILE_READ_ERROR));
	game.move_count = 0;
	if (verify_map(&game) == 1)
	{
		free_array(game.map);
		return (0);
	}
	launch(&game);
	free_game(&game);
	return (0);
}
