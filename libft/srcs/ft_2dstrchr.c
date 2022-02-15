/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2dstrchr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouabda <ibouabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 15:35:35 by idris             #+#    #+#             */
/*   Updated: 2020/02/01 14:02:18 by ibouabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/libft.h"

int	ft_2dstrchr(char **str, char c, t_fpoint *a)
{
	int y;
	int x;

	y = 0;
	while (str[y])
	{
		x = 0;
		while (str[y][x])
		{
			if (str[y][x] == c)
			{
				a->x = (int)x;
				a->y = (int)y;
				return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}
