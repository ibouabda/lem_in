/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puttabint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retounsi <retounsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 10:52:15 by ibouabda          #+#    #+#             */
/*   Updated: 2019/12/01 18:05:16 by retounsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/libft.h"

void	ft_puttabint(int *tab, int size)
{
	int i;

	i = 0;
	if (!tab)
		return ;
	while (i < size)
	{
		ft_putnbr(tab[i]);
		ft_putstr(" ");
		i++;
	}
	ft_putendl("");
}
