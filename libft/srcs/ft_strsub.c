/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouabda <ibouabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 19:11:26 by ibouabda          #+#    #+#             */
/*   Updated: 2019/10/10 20:01:37 by ibouabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *d;

	if ((int)len < 0 || s == NULL)
		return (NULL);
	if (!(d = ft_strnew(len)))
		return (NULL);
	d = ft_strncpy(d, &((char*)s)[start], len);
	d[len] = '\0';
	return (d);
}
