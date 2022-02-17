# include "lem_in.h"

static t_room_list	*allocate_room(char *name, int coord_x, int coord_y)
{
	t_room		*room;
	t_room_list	*room_link;
	size_t		room_size;
	size_t		room_link_size;

	room_size = sizeof(t_room); // Alloue la room
	room = (t_room*)ft_memalloc(room_size);
	ft_bzero(room, room_size);
	if (!(room->name = ft_strnew_cpy(name)))
	{
		ft_memdel(&room);
		return (NULL);
	}
	room->coord_x = coord_x;
	room->coord_y = coord_y;
	room_link_size = sizeof(t_room_list); // Alloue la room_list
	room_link = (t_room_list*)ft_memalloc(room_link_size);
	room_link->room = room;
	room_link->next = NULL;
	return (room_link);
}

static char			fill_room(t_env *env, char **split, t_room_list *last_room,
	char *bool_is_start_is_end)
{
	t_room_list	*room_link = NULL;
	char		ret = 0;

	room_link = allocate_room(split[0], split[1], split[2]);
	if (!last_room) // Si la room est la premiere de la liste
		env->rooms = room_link;
	else
		last_room->next = room_link;
	last_room = room_link;
	if ((*bool_is_start_is_end == 2 && env->start)
		|| (*bool_is_start_is_end == 1 && env->end)) // S'il y a plusieurs start ou end
		ret = 1;
	else if (*bool_is_start_is_end == 2 && !env->start) // Commande start
	{
		env->start = room_link->room;
		*bool_is_start_is_end = 0;
	}
	else if (*bool_is_start_is_end == 1 && !env->end) // Commande end
	{
		env->end = room_link->room;
		*bool_is_start_is_end = 0;
	}
	return (ret);
}

char				get_room(t_env *env, char **line, t_room_list *last_room,
	t_bool_parse *bool_parse)
{
	char		**split = NULL;
	int			i_split = 0;
	int			nb_str_in_split = 0;
	char		ret = 0;

	split = ft_strsplit(line, ' ');
	while (split[i_split++])
		nb_str_in_split++;
	if (nb_str_in_split == 1) // C'est que l'on a switch sur les pipes
		ret = get_pipe(env, split[1], &(bool_parse->step_frp));
	else if (nb_str_in_split == 3) // Si on a le bon nombre
		ret = fill_room(env, split, last_room, &(bool_parse.is_start_is_end));
	else
		ret = 1;
	ft_2dstrdel(split);
	return (ret);
}