/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khelegbe <khelegbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 23:36:45 by khelegbe          #+#    #+#             */
/*   Updated: 2022/01/22 02:02:29 by khelegbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_digits(unsigned int nb)
{
	int	len;

	len = 0;
	if (nb <= 0)
	{
		nb = nb * -1;
		len++;
	}
	while (nb)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

char	*ft_utoa(unsigned int n)
{
	char			*str;
	unsigned int	nbr;
	int				len;

	nbr = n;
	str = 0;
	len = ft_count_digits(nbr);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	if (n == 0)
		str[0] = '0';
	str[len] = '\0';
	while (nbr)
	{
		str[--len] = '0' + nbr % 10;
		nbr = nbr / 10;
	}
	return (str);
}
