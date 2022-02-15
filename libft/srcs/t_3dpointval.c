/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_3dpointval.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouabda <ibouabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 14:07:25 by ibouabda          #+#    #+#             */
/*   Updated: 2019/10/10 20:01:37 by ibouabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/libft.h"

void	t_3dpointval(t_3dpoint *point, int x, int y, int z)
{
	point->x = x;
	point->y = y;
	point->z = z;
}
