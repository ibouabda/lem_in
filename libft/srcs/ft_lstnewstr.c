/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnewstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouabda <ibouabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 17:52:36 by ibouabda          #+#    #+#             */
/*   Updated: 2019/10/10 20:01:37 by ibouabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/libft.h"

t_list	*ft_lstnewstr(char *content, size_t content_size)
{
	t_list *newlist;

	if (!(newlist = (t_list *)malloc(sizeof(t_list))))
	{
		ft_putendl("ft_lstnewstr malloc error");
		exit(EXIT_FAILURE);
	}
	if (content == NULL)
	{
		newlist->content = NULL;
		content_size = 0;
	}
	else
	{
		newlist->content = ft_strdup(content);
		newlist->content_size = content_size;
	}
	newlist->next = NULL;
	return (newlist);
}
