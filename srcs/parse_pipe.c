# include "lem_in.h"

static void	link_rooms(t_room *room_a, t_room_list *room_link)
{
	t_room_list	*lst = NULL;

	if (room_a->link)
	{
		lst = room_a->link;
		while (lst->next)
			lst = lst->next;
		lst->next = room_link;
	}
	else
		room_a->link = room_link;
}

static char	alloc_link_rooms_pipes(t_room *room_a, t_room *room_b)
{
	t_room_list	*room_link_a = NULL;
	t_room_list	*room_link_b = NULL;
	size_t		room_list_size = sizeof(t_room_list);

	if (!(room_link_a = (t_room_list*)ft_memalloc(room_list_size)))
		return (1);
	else if (!(room_link_b = (t_room_list*)ft_memalloc(room_list_size)))
	{
		ft_memdel((void**)&room_link_a);
		return (1);
	}
	room_link_a->room = room_b;
	room_link_a->next = NULL;
	room_link_b->room = room_a;
	room_link_b->next = NULL;
	link_rooms(room_a, room_link_a);
	link_rooms(room_b, room_link_b);
	return (0);
}

static char	get_rooms_pipes(t_env *env, char *room_name_a, char *room_name_b)
{
	t_room_list	*room_list = env->rooms;
	t_room		*room_a = NULL;
	t_room		*room_b = NULL;

	while (room_list && room_list->room && room_list->room->name)
	{
		if (!ft_strcmp(room_list->room->name, room_name_a))
			room_a = room_list->room;
		else if (!ft_strcmp(room_list->room->name, room_name_b))
			room_b = room_list->room;
		room_list = room_list->next;
	}
	if (!room_a || !room_b)
		return (1);
	alloc_link_rooms_pipes(room_a, room_b);
	return (0);
}

static char	pipe_split_dash(t_env *env, char *line)
{
	char		**split_dash = NULL;
	int			i_split_dash = 0;
	int			nb_str_in_split_dash = 0;
	char		ret = 0;

	if (!(split_dash = ft_strsplit(line, '-')))
		return (1);
	while (split_dash[i_split_dash++])
		nb_str_in_split_dash++;
	if (nb_str_in_split_dash != 2)
		ret = 1;
	else
		ret = get_rooms_pipes(env, split_dash[0], split_dash[1]);
	ft_2dstrdel(split_dash);
	return (ret);
}

char		get_pipe(t_env *env, char *line)
{
	char		**split_space = NULL;

	if (!(split_space = ft_strsplit(line, ' ')))
		return (1);
	pipe_split_dash(env, split_space[0]);
	ft_2dstrdel(split_space);
	return (0);

}