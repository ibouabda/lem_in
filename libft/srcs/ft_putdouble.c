/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdouble.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouabda <ibouabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 16:37:15 by ibouabda          #+#    #+#             */
/*   Updated: 2019/10/10 20:01:37 by ibouabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/libft.h"

void	ft_putdouble(double n, int *i)
{
	unsigned int tmp;

	if (n < 0)
	{
		ft_putchar('-');
		tmp = -n;
		*i += 1;
	}
	else
		tmp = n;
	if (tmp >= 10)
	{
		*i += 1;
		ft_putnbr_count(tmp / 10, i);
	}
	ft_putchar('0' + tmp % 10);
}
