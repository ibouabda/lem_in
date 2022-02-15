/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnewd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouabda <ibouabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 10:32:26 by ibouabda          #+#    #+#             */
/*   Updated: 2019/10/10 20:01:37 by ibouabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/libft.h"

t_list	*ft_lstnewd(void *content, size_t content_size)
{
	t_list *newlist;

	if (!(newlist = (t_list *)malloc(sizeof(t_list))))
	{
		ft_putendl("ft_lstnew malloc error");
		exit(EXIT_FAILURE);
	}
	newlist->content = content;
	newlist->content_size = content_size;
	newlist->next = NULL;
	return (newlist);
}
