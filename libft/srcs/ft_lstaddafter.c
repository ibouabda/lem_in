/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddafter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouabda <ibouabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 19:33:31 by ibouabda          #+#    #+#             */
/*   Updated: 2019/10/10 20:01:37 by ibouabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/libft.h"

void	ft_lstaddafter(t_list **alst, t_list *new)
{
	t_list *m;
	t_list *tmp;

	m = *alst;
	if (*alst == NULL)
		*alst = new;
	else if (m->next == NULL)
		m->next = new;
	else if (m->next)
	{
		tmp = m->next;
		m->next = new;
		new->next = tmp;
	}
}
