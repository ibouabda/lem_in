/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouabda <ibouabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 16:06:39 by ibouabda          #+#    #+#             */
/*   Updated: 2019/10/10 20:01:37 by ibouabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/libft.h"

char	*ft_strchr(const char *src, int c)
{
	int		i;
	char	*mysrc;

	mysrc = (char*)src;
	i = 0;
	while (c != mysrc[i] && mysrc[i] != '\0')
		i++;
	if (mysrc[i] == c)
		return (mysrc + i);
	else
		return (NULL);
}
