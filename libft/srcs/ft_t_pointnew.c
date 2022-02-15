/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_t_pointnew.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouabda <ibouabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 13:09:37 by ibouabda          #+#    #+#             */
/*   Updated: 2019/10/10 20:01:37 by ibouabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/libft.h"

t_point	*ft_t_pointnew(int x, int y)
{
	t_point *point;

	if (!(point = (t_point*)malloc(sizeof(t_point))))
	{
		ft_putendl("malloc error t_point");
		exit(EXIT_FAILURE);
	}
	point->x = x;
	point->y = y;
	return (point);
}
