/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khelegbe <khelegbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 14:14:53 by khelegbe          #+#    #+#             */
/*   Updated: 2022/01/22 01:56:14 by khelegbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	int		j;

	i = 0;
	j = 0;
	while (i < n)
	{
		j = *(unsigned char *)s1++ - *(unsigned char *)s2++;
		if (j)
			return (j);
		i++;
	}
	return (0);
}
