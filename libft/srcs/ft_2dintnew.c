/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2dintnew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouabda <ibouabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 18:04:15 by idris             #+#    #+#             */
/*   Updated: 2019/10/10 20:01:37 by ibouabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/libft.h"

int	**ft_2dintnew(size_t size)
{
	int		**str;
	size_t	i;

	i = 0;
	if (!(str = (int**)malloc(sizeof(int*) * (size + 1))))
	{
		ft_putendl("ft_2dintnew malloc error");
		exit(EXIT_FAILURE);
	}
	while (i < (size + 1))
	{
		str[i] = NULL;
		i++;
	}
	return (str);
}
