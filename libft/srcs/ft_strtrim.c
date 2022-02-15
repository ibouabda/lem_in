/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouabda <ibouabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 11:13:02 by ibouabda          #+#    #+#             */
/*   Updated: 2019/10/10 20:01:37 by ibouabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/libft.h"

char	*ft_strtrim(char const *s)
{
	size_t i;
	size_t k;

	if (s)
	{
		i = 0;
		k = 0;
		while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && s[i])
			i++;
		while (s[k + 1] != '\0')
			k++;
		while ((s[k] == ' ' || s[k] == '\n' || s[k] == '\t') && k > 0)
			k--;
		if (!s[i])
			return (ft_strnew(0));
		return (ft_strsub(s, i, (k - i) + 1));
	}
	return (NULL);
}
