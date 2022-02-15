/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouabda <ibouabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 14:57:08 by ibouabda          #+#    #+#             */
/*   Updated: 2019/10/10 20:01:37 by ibouabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/libft.h"

void	ft_putnbr(int n)
{
	unsigned int tmp;

	if (n < 0)
	{
		ft_putchar('-');
		tmp = -n;
	}
	else
		tmp = n;
	if (tmp >= 10)
	{
		ft_putnbr(tmp / 10);
	}
	ft_putchar('0' + tmp % 10);
}
