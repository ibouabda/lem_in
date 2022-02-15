/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouabda <ibouabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 10:19:57 by ibouabda          #+#    #+#             */
/*   Updated: 2019/10/10 20:01:37 by ibouabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *mys1;
	char *mys2;
	char *dest;

	if (s1 && s2)
	{
		mys1 = (char *)s1;
		mys2 = (char *)s2;
		if (!(dest = ft_strnew(ft_strlen(mys1) + ft_strlen(mys2))))
		{
			ft_putendl("ok");
			return (NULL);
		}
		return (ft_strcat(ft_strcpy(dest, mys1), mys2));
	}
	return (NULL);
}
