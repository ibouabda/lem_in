/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_3dputstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouabda <ibouabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 13:30:16 by ibouabda          #+#    #+#             */
/*   Updated: 2019/10/10 20:01:37 by ibouabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/libft.h"

void	ft_3dputstr(char ***tetrim)
{
	size_t i;
	size_t k;

	i = 0;
	k = 0;
	while (tetrim[i])
	{
		while (tetrim[i][k])
		{
			ft_putendl(tetrim[i][k]);
			k++;
		}
		ft_putchar('\n');
		k = 0;
		i++;
	}
}
