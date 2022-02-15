/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2dstrcmp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouabda <ibouabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 16:18:54 by retounsi          #+#    #+#             */
/*   Updated: 2019/10/10 20:01:37 by ibouabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/libft.h"

int	ft_2dstrcmp(char **s1, char **s2)
{
	size_t i;

	i = 0;
	while (s2[i] || s1[i])
	{
		if (s1[i] && s2[i])
		{
			if (ft_strcmp(s1[i], s2[i]) != 0)
				return (0);
		}
		else
			return (0);
		i++;
	}
	return (1);
}
