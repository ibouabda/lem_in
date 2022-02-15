/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmanynew.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouabda <ibouabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 17:16:34 by ibouabda          #+#    #+#             */
/*   Updated: 2019/10/10 20:01:37 by ibouabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/libft.h"

t_list	*ft_lstmanynew(size_t lst, void const *content, size_t content_size)
{
	size_t i;
	t_list *m;
	t_list *ref;

	i = 0;
	m = NULL;
	ft_lstaddend(&m, ft_lstnew(content, content_size));
	i++;
	ref = m;
	while (i < lst)
	{
		ft_lstaddend(&m, ft_lstnew(content, content_size));
		i++;
	}
	return (ref);
}
