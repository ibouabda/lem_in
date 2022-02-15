/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouabda <ibouabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 17:03:51 by ibouabda          #+#    #+#             */
/*   Updated: 2019/10/10 20:01:37 by ibouabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *newlst;
	t_list *m;
	t_list *newm;

	m = lst;
	newlst = ft_lstnew(f(m)->content, f(m)->content_size);
	m = m->next;
	newm = newlst;
	while (m)
	{
		newm->next = ft_lstnew(f(m)->content, f(m)->content_size);
		newm = newm->next;
		m = m->next;
	}
	return (newlst);
}
