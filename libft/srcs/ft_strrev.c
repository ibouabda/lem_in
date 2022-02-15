/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouabda <ibouabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 14:21:59 by ibouabda          #+#    #+#             */
/*   Updated: 2019/06/20 15:57:22 by ibouabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(char *a, char *b)
{
	char tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

char	*ft_strrev(char *str)
{
	int i;
	int c;

	c = 0;
	i = 0;
	while (str[c] != '\0')
	{
		c++;
	}
	c--;
	while (i <= c / 2)
	{
		ft_swap(&str[i], &str[c - i]);
		i++;
	}
	return (str);
}
