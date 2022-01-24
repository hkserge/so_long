/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khelegbe <khelegbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 17:45:01 by khelegbe          #+#    #+#             */
/*   Updated: 2022/01/22 02:01:15 by khelegbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_str_nb(const char *s, char c)
{
	size_t	i;
	size_t	nb_strs;

	if (!s[0])
		return (0);
	i = 0;
	nb_strs = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c)
		{
			nb_strs++;
			while (s[i] && s[i] == c)
				i++;
			continue ;
		}
		i++;
	}
	if (s[i - 1] != c)
		nb_strs++;
	return (nb_strs);
}

static char	*ft_get_next_str(char const *s, char c, size_t *i)
{
	size_t	end;
	char	*str;

	if (!s[0])
		return (0);
	while (s[*i] && s[*i] == c)
		(*i)++;
	end = *i;
	while (s[end])
	{
		if (s[end] == c)
		{
			str = ft_substr(s, *i, (size_t)end - *i);
			*i = end;
			return (str);
		}
		end++;
	}
	if (s[end] - 1 != c)
		return (ft_substr(s, *i, (size_t)end - *i));
	return (0);
}

static void	ft_clear_tab(char **str)
{
	while (*str)
	{
		free(*str);
		str++;
	}
	free(str);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	char	**str;
	int		len;
	size_t	j;

	if (!s)
		return (0);
	i = 0;
	len = ft_str_nb(s, c);
	j = 0;
	str = malloc(sizeof(char *) * (len + 1));
	if (!str)
		return (0);
	while (i < len)
	{
		str[i] = ft_get_next_str(s, c, &j);
		if (!str[i])
		{
			ft_clear_tab(str);
			return (0);
		}
		i++;
	}
	str[i] = NULL;
	return (str);
}
