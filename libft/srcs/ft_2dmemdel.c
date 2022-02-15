/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2dmemdel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retounsi <retounsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 14:29:54 by ibouabda          #+#    #+#             */
/*   Updated: 2019/12/04 15:04:06 by retounsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/libft.h"
#include <stdio.h>

void	ft_2dmemdel(void **as)
{
	size_t i;

	i = 0;
	if (as != NULL)
	{
		while (as[i])
		{
			free(as[i]);
			i++;
		}
		free(as);
		as = NULL;
	}
}
