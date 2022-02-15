/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_maj.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouabda <ibouabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 16:13:20 by ibouabda          #+#    #+#             */
/*   Updated: 2020/02/01 18:56:30 by ibouabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/libft.h"

int		size_base_maj(int nb, int base)
{
	int	i;

	i = 1;
	while (nb != 0)
	{
		nb = nb / base;
		i++;
	}
	return (i);
}

char	*ft_itoa_base_maj(int nb, int base)
{
	char	*base_def;
	char	*number;
	int		minus;
	int		size;
	int		i;

	i = 0;
	minus = 0;
	base_def = "0123456789ABCDEF";
	if (base == 10)
		minus = 1;
	size = size_base_maj(nb, base) + minus;
	number = ft_strnew(size);
	while (nb != 0)
	{
		number[i] = base_def[abs(nb % base)];
		nb = nb / base;
		i++;
	}
	if (minus == 1)
	{
		number[i] = '-';
	}
	ft_strrev(number);
	return (number);
}
