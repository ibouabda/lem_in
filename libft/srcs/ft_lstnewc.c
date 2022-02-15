/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnewc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouabda <ibouabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 16:55:49 by ibouabda          #+#    #+#             */
/*   Updated: 2019/10/10 20:01:37 by ibouabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/libft.h"

t_list	*ft_lstnewc(void *content, size_t c)
{
	t_list *newlist;

	if (!(newlist = (t_list *)malloc(sizeof(t_list))))
	{
		ft_putendl("ft_lstnewc malloc error");
		exit(EXIT_FAILURE);
	}
	newlist->content_size = c;
	newlist->content = content;
	newlist->next = NULL;
	return (newlist);
}
