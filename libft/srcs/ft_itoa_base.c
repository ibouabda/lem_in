/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouabda <ibouabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 13:28:35 by ibouabda          #+#    #+#             */
/*   Updated: 2020/02/01 18:56:20 by ibouabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/libft.h"

int		size_base(int nb, int base)
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

char	*ft_itoa_base(int nb, int base)
{
	char	*base_def;
	char	*number;
	int		minus;
	int		size;
	int		i;

	i = 0;
	minus = 0;
	base_def = "0123456789abcdef";
	if (base == 10)
		minus = 1;
	size = size_base(nb, base) + minus;
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
