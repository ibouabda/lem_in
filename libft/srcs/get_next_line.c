/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouabda <ibouabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 15:31:27 by ibouabda          #+#    #+#             */
/*   Updated: 2019/10/10 20:01:37 by ibouabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/libft.h"
#include "stdio.h"

t_prlist	*ft_prlistnewstr(char *content, int fd, t_prlist *prev)
{
	t_prlist	*newlist;

	if (!(newlist = (t_prlist *)malloc(sizeof(t_prlist))))
		return (NULL);
	if (content == NULL)
	{
		newlist->content = NULL;
		fd = 0;
	}
	else
	{
		newlist->content = content;
		newlist->fd = fd;
	}
	newlist->prev = prev;
	newlist->next = NULL;
	return (newlist);
}

void		takeline(char *buf, char **line)
{
	int		i;
	size_t	size;

	i = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	*line = ft_strsub(buf, 0, i);
	size = ft_strlen(buf);
	ft_memmove(buf, buf + (i + 1), size - i);
	buf[size - i] = '\0';
}

void		ft_chooseid(t_prlist **id, const int fd)
{
	while ((*id)->prev)
		(*id) = (*id)->prev;
	while ((*id)->next && (*id)->fd != fd)
		(*id) = (*id)->next;
	if ((*id) && (*id)->fd != fd)
	{
		(*id)->next = ft_prlistnewstr(ft_strnew(0), fd, (*id));
		(*id) = (*id)->next;
	}
}

int			ft_prlstdellink(t_prlist **id)
{
	t_prlist **m;

	m = id;
	if ((*id)->prev && (*id)->next)
	{
		(*id)->prev->next = (*id)->next;
		(*id)->next->prev = (*id)->prev;
		(*id) = (*id)->prev;
	}
	else if ((*id)->next)
	{
		(*id) = (*id)->next;
		(*id)->prev = NULL;
	}
	else if ((*id)->prev)
	{
		(*id) = (*id)->prev;
		(*id)->next = NULL;
	}
	if ((*m)->content)
		ft_memdel((void**)&((*m)->content));
	ft_memdel((void**)m);
	return (0);
}

int			get_next_line(const int fd, char **line)
{
	static t_prlist	*id;
	char			*buftmp;
	char			*todel;
	int				red;

	red = -1;
	buftmp = ft_strnew(BUFF_SIZE + 1);
	if (!line || (read(fd, buftmp, 0)) == -1)
		return (-1);
	id = !id ? ft_prlistnewstr(ft_strnew(0), fd, NULL) : id;
	if (id->fd != fd)
		ft_chooseid(&id, fd);
	while (!ft_strchr(id->content, '\n') &&
	(red = read(id->fd, buftmp, BUFF_SIZE)))
	{
		buftmp[red] = '\0';
		todel = id->content;
		id->content = ft_strjoin(todel, buftmp);
		ft_strdel(&todel);
	}
	ft_strdel(&buftmp);
	takeline(id->content, line);
	if (red == 0 && !((char *)id->content)[0])
		return (ft_prlstdellink(&id));
	return (1);
}
