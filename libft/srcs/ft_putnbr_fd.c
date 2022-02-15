/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouabda <ibouabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 15:14:32 by ibouabda          #+#    #+#             */
/*   Updated: 2019/10/10 20:01:37 by ibouabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int tmp;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		tmp = -n;
	}
	else
		tmp = n;
	if (tmp >= 10)
	{
		ft_putnbr_fd(tmp / 10, fd);
	}
	ft_putchar_fd('0' + tmp % 10, fd);
}
