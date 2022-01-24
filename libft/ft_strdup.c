/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khelegbe <khelegbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 18:58:40 by khelegbe          #+#    #+#             */
/*   Updated: 2022/01/22 01:48:00 by khelegbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*tmp;
	size_t	len;

	len = ft_strlen(s);
	tmp = malloc(sizeof(*s) * (len + 1));
	if (!tmp)
		return (0);
	ft_strlcpy(tmp, s, len + 1);
	return (tmp);
}
