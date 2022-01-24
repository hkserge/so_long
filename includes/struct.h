/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khelegbe <khelegbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 15:59:54 by khelegbe          #+#    #+#             */
/*   Updated: 2022/01/21 16:16:32 by khelegbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_coord
{
	int	x;
	int	y;
}	t_coord;

typedef struct s_map
{
	t_list	*lines;
}	t_map;

typedef struct s_game
{
	char	**map;
	int		consomable_left;
	int		move_count;
	t_coord	player_pos;
	void	*mlx;
	void	*mlx_win;
	void	*player;
	void	*consomable;
	void	*exit;
	void	*wall;
	void	*floor;
}	t_game;

typedef struct s_required
{
	int	player;
	int	consomable;
	int	exit;
}	t_required;

#endif
