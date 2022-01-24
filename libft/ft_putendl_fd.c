/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khelegbe <khelegbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 14:28:22 by khelegbe          #+#    #+#             */
/*   Updated: 2020/12/06 14:39:51 by khelegbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	char	nline;

	nline = '\n';
	if (!fd || !s)
		return ;
	while (*s)
	{
		write(fd, &(*s), 1);
		s++;
	}
	write(fd, &nline, 1);
}
