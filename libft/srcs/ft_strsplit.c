/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouabda <ibouabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 17:45:01 by ibouabda          #+#    #+#             */
/*   Updated: 2019/10/10 20:01:37 by ibouabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/libft.h"

static int	ft_mesure_index(char *str, char c)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[i])
	{
		while ((str[i] == c) && str[i])
		{
			i++;
		}
		if (str[i] != '\0')
		{
			while (str[i] != c && str[i])
			{
				i++;
			}
			j++;
		}
	}
	return (j);
}

static char	**ft_fill_index(char **index, char *str, char c)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	while (str[i])
	{
		while ((str[i] == c) && str[i])
		{
			i++;
		}
		if (str[i])
		{
			k = 0;
			while (str[i] != c && str[i])
				index[j][k++] = str[i++];
			index[j][k] = '\0';
			j++;
		}
	}
	return (index);
}

static char	**ft_malloc_str(char **index, char *str, char c)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	while (str[i])
	{
		while ((str[i] == c) && str[i])
			i++;
		if (str[i])
		{
			k = 0;
			while (str[i] != c && str[i])
			{
				k++;
				i++;
			}
			if (!(index[j++] = (char *)malloc(sizeof(char) * (k))))
				return (NULL);
		}
	}
	return (index);
}

char		**ft_strsplit(char const *str, char c)
{
	char	**index;
	int		j;
	char	*str2;

	if (str)
	{
		str2 = ft_strdup(str);
		j = ft_mesure_index(str2, c);
		if (!(index = (char **)malloc(sizeof(char *) * (j + 1))))
		{
			ft_putendl("ft_lstnewstr malloc error");
			exit(EXIT_FAILURE);
		}
		index[j] = 0;
		index = ft_malloc_str(index, str2, c);
		return (ft_fill_index(index, str2, c));
	}
	return (NULL);
}
