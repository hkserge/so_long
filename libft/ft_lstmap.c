/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khelegbe <khelegbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 23:19:17 by khelegbe          #+#    #+#             */
/*   Updated: 2022/01/22 01:50:56 by khelegbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *l, void *(*f)(void*), void (*d)(void*))
{
	t_list		*new_lst;
	t_list		*new_elem;

	if (!l || !f)
		return (0);
	new_lst = 0;
	while (l)
	{
		new_elem = ft_lstnew(f(l->content));
		if (!new_elem)
		{
			ft_lstclear(&new_lst, d);
			return (0);
		}
		ft_lstadd_back(&new_lst, new_elem);
		l = l->next;
	}
	return (new_lst);
}
