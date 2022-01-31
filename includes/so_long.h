/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khelegbe <khelegbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 16:09:19 by khelegbe          #+#    #+#             */
/*   Updated: 2022/01/31 14:51:46 by khelegbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "constant.h"
# include "struct.h"
# include <fcntl.h>

/*
**	FILE - srcs/utils.c
*/

int		print_error(char *str);
int		check_extension(char *str);
char	**read_file(int fd);
int		open_file(char *path);
char	**lst_to_array(t_list *lines);

/*
**	FILE - srcs/utils2.c
*/

int		ft_arraylen(char **array);
int		checking_file(char *arg);
void	get_player_pos(char **map, t_coord *pos);

/*
**	FILE - srcs/utils_checkmap.c
*/

int		verify_map(t_game *game);

/*
**	FILE - srcs/engine.c
*/

void	launch(t_game *game);
int		exit_game(t_game *conf);
void	draw_count(t_game *game);

/*
**	FILE - srcs/engine2.c
*/

int		draw_map(t_game *game);
int		key_hook(int keycode, t_game *game);
void	destroy_image(void *mlx, void *sprite);

/*
**	FILE - srcs/moves.c
*/

void	moves(t_game *game, int direction);

/*
**	FILE - srcs/utils_mem.c
*/

void	free_array(char **array);
void	free_game(t_game *game);

#endif
