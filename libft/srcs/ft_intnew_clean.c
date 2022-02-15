/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intnew_clean.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retounsi <retounsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 10:47:47 by retounsi          #+#    #+#             */
/*   Updated: 2019/12/02 10:55:14 by retounsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/libft.h"

int	*ft_intnew_clean(int size)
{
	int	*tab;

	if (!(tab = (int*)malloc(sizeof(int) * (size))))
	{
		ft_putendl("ft_intnew malloc error");
		exit(EXIT_FAILURE);
	}
	while (size > 0)
	{
		size--;
		tab[size] = -1;
	}
	return (tab);
}
