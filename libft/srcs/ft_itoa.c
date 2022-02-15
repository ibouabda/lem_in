/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouabda <ibouabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 17:48:52 by ibouabda          #+#    #+#             */
/*   Updated: 2019/10/10 20:01:37 by ibouabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/libft.h"

char	*ft_itoa(int n)
{
	size_t			length;
	unsigned int	tmp;
	char			*str;

	tmp = ((n < 0) ? -n : n);
	length = ((n < 0) ? 2 : 1);
	while (tmp)
	{
		tmp = tmp / 10;
		length++;
	}
	if (!(str = ft_strnew(length)))
		return (NULL);
	length--;
	str[0] = ((n < 0) ? '-' : '0');
	tmp = ((n < 0) ? -n : n);
	while (tmp && length--)
	{
		str[length] = '0' + tmp % 10;
		tmp = tmp / 10;
	}
	return (str);
}
