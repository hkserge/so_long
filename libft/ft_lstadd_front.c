/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khelegbe <khelegbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 21:42:18 by khelegbe          #+#    #+#             */
/*   Updated: 2020/12/15 21:56:54 by khelegbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **alst, t_list *newlst)
{
	if (!newlst)
		return ;
	if (!*alst)
	{
		*alst = newlst;
		return ;
	}
	newlst->next = *alst;
	*alst = newlst;
}
