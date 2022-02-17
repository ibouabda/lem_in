# include "lem_in.h"

static t_ant_list	*alloc_ant_list(t_room *start_room, int i)
{
	t_ant		*ant;
	t_ant_list	*ant_link;
	size_t		ant_size;
	size_t		ant_link_size;

	ant_size = sizeof(t_ant); // Alloue la fourmi
	if (!(ant = (t_ant*)ft_memalloc(ant_size)))
		return (NULL);
	ft_bzero(ant, ant_size);
	ant->id = i;
	ant->arrived = 0;
	ant->actual_room = start_room;
	ant_link_size = sizeof(t_ant_list); // Alloue la ant_list
	if (!(ant_link = (t_ant_list*)ft_memalloc(ant_link_size)))
	{
		ft_memdel((void**)&ant);
		return (NULL);
	}
	ant_link->ant = ant;
	ant_link->next = NULL;
	return (ant_link);
}

char			alloc_ants(t_env *env)
{
	unsigned int	i = 0;
	t_ant_list		*ant_link = env->ants;

	while (i < env->ant_nbr)
	{
		if (!ant_link) // Si on est au debut de la liste
		{
			env->ants = alloc_ant_list(env->start, i++);
			ant_link = env->ants;
		}
		else
		{
			ant_link->next = alloc_ant_list(env->start, i++);
			ant_link = ant_link->next;
		}
		if (!ant_link) // Si l'allocation a echoue
			return (1);
	}
	return (0);
}