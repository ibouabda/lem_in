# include "lem_in.h"

static void	erase_ants(t_ant_list *ant_list)
{
	if (ant_list->next)
		erase_ants(ant_list->next);
	if (ant_list->ant)
		ft_memdel((void**)&(ant_list->ant));
	ft_memdel((void**)&ant_list);
}

static void	erase_room_link(t_room_list *room_link)
{
	if (room_link->next)
		erase_room_link(room_link->next);
	ft_memdel((void**)&room_link);
}

static void	erase_rooms_pipes(t_room_list *room_list)
{
	if (room_list->next)
		erase_rooms_pipes(room_list->next);
	if (room_list->room)
	{
		if (room_list->room->name)
			ft_memdel((void**)&(room_list->room->name));
		if (room_list->room->link)
			erase_room_link(room_list->room->link);
		ft_memdel((void**)&(room_list->room));
	}
	ft_memdel((void**)&room_list);
}

void	erase_anthill(t_env *env)
{
	if (env->rooms)
		erase_rooms_pipes(env->rooms);
	if (env->ants)
		erase_ants(env->ants);
	env->start = NULL;
	env->end = NULL;
}