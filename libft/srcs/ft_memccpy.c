/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouabda <ibouabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 14:50:35 by ibouabda          #+#    #+#             */
/*   Updated: 2019/10/10 20:01:37 by ibouabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t	i;
	char	myc;
	char	*mysrc;
	char	*mydest;

	myc = (unsigned char)c;
	mysrc = (char*)src;
	mydest = (char*)dest;
	i = 0;
	while (i < n)
	{
		mydest[i] = mysrc[i];
		if (mysrc[i] == myc)
			return (&mydest[i + 1]);
		i++;
	}
	return (NULL);
}
