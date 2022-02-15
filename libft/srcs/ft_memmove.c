/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouabda <ibouabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 14:55:30 by ibouabda          #+#    #+#             */
/*   Updated: 2019/10/10 20:01:37 by ibouabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/libft.h"

void static	*increase(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*mysrc;
	char	*mydest;

	mysrc = (char *)src;
	mydest = (char *)dest;
	i = 0;
	while (i < n)
	{
		mydest[i] = mysrc[i];
		i++;
	}
	return (dest);
}

void static	*decrease(void *dest, const void *src, size_t n)
{
	int		i;
	char	*mysrc;
	char	*mydest;

	mysrc = (char *)src;
	mydest = (char *)dest;
	i = n - 1;
	while (i >= 0)
	{
		mydest[i] = mysrc[i];
		i--;
	}
	return (dest);
}

void		*ft_memmove(void *dest, const void *src, size_t n)
{
	if (dest == src)
		return (dest);
	if (dest > src)
		decrease(dest, src, n);
	else
		increase(dest, src, n);
	return (dest);
}
