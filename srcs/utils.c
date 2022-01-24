/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khelegbe <khelegbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 17:07:39 by khelegbe          #+#    #+#             */
/*   Updated: 2022/01/21 17:07:44 by khelegbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	print_error(char *str)
{
	ft_putendl_fd("Error.", STDOUT_FILENO);
	ft_putendl_fd(str, STDOUT_FILENO);
	return (1);
}

int	check_extension(char *str)
{
	int		out;
	char	*point_pos;

	point_pos = ft_strrchr(str, '.');
	out = 0;
	if (point_pos != NULL)
		out = ft_strncmp(point_pos, ".ber", 5) == 0;
	if (out == 0)
		return (print_error(BAD_MAP_EXTENTION));
	return (0);
}

int	open_file(char *path)
{
	int	fd;

	fd = open(path, O_DIRECTORY);
	if (fd < 0)
	{
		fd = open(path, O_RDONLY | O_NOFOLLOW);
		if (fd < 0)
			print_error(FILE_IS_SYMLINK);
		return (fd);
	}
	else
	{
		close(fd);
		print_error(FILE_IS_DIRECTORY);
		return (-1);
	}
}

char	**lst_to_array(t_list *lines)
{
	char	**array;
	int		size;
	int		i;

	i = 0;
	size = 0;
	size = ft_lstsize(lines);
	if (size == 0)
		return (NULL);
	array = malloc(sizeof(char **) * (size + 1));
	if (array == NULL)
		return (NULL);
	while (i < size)
	{
		array[i] = ft_strdup((char *)lines->content);
		lines = lines->next;
		i++;
	}
	array[i] = NULL;
	return (array);
}

char	**read_file(int fd)
{
	int		result;
	t_list	*lines;
	char	*nextline;
	char	**map;

	result = 1;
	nextline = NULL;
	lines = NULL;
	while (result == 1)
	{
		result = get_next_line(fd, &nextline);
		if (result == -1)
		{
			ft_lstclear(&lines, free);
			free(nextline);
			return (NULL);
		}
		if (result != 0)
			ft_lstadd_back(&lines, ft_lstnew(nextline));
		else
			free(nextline);
	}
	map = lst_to_array(lines);
	ft_lstclear(&lines, free);
	return (map);
}
