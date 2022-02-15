/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_3dstrin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouabda <ibouabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 16:38:54 by retounsi          #+#    #+#             */
/*   Updated: 2019/10/10 20:01:37 by ibouabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/libft.h"

int	ft_2dstrin(char **s1, char ***s2)
{
	size_t i;

	i = 0;
	while (s2[i])
	{
		if (ft_2dstrcmp(s1, s2[i]) == 1)
			return (1);
		i++;
	}
	return (0);
}

int	ft_3dstrin(char ***s1, char ***s2)
{
	size_t	i;

	i = 0;
	while (s1[i])
	{
		if (ft_2dstrin(s1[i], s2) == 0)
			return (0);
		i++;
	}
	return (1);
}
