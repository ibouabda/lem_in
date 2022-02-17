#include "lem_in.h"

static char			check_comment(char *line)
{
	if (ft_strlen(line) > 0 && line[0] == '#' && line[1] != '#')
		return (1);
	return (0);
}

static char			check_command(t_env *env, char *line, char *is_start_is_end)
{
	char	**split = NULL;
	int		i_split = 0;
	int		nb_str_in_split = 0;

	if (ft_strlen(line) > 1 && line[0] == '#' && line[1] == '#')
	{
		split = ft_strsplit(line, ' ');
		while (split[i_split++])
			nb_str_in_split++;
		if (nb_str_in_split != 1)
			(void)nb_str_in_split;
		else if (!ft_strcmp(line, start))
			*is_start_is_end = 1 << 1; // start 1
		else if (!ft_strcmp(line, end))
			*is_start_is_end = 1; // end 1
		ft_2dstrdel(split);
		return (1);
	}
	return (0);
}

static void			get_ant_nbr(int *nbr, char *line, char *bool_step_frp)
{
		bool_step_frp = 1 << 1; // room_step = 1;
		env->ant_nbr = ft_atoi(line);
}

static t_ant_list	alloc_ant_list(t_room *start_room, int i)
{
	t_ant		*ant;
	t_ant_list	*ant_link;
	size_t		ant_size;
	size_t		ant_link_size;

	ant_size = sizeof(t_ant); // Alloue la fourmi
	if (!(ant = (t_ant*)ft_memalloc(ant_size))
		return (NULL);
	ft_bzero(ant, ant_size);
	ant->id = i;
	ant->arrived = 0;
	ant->actual_room = start_room;
	ant_link_size = sizeof(t_ant_list); // Alloue la ant_list
	if (!(ant_link = (t_ant_list*)ft_memalloc(ant_link_size))
	{
		ft_memdel(&ant);
		return (NULL);
	}
	ant_link->ant = ant;
	ant_link->next = NULL;
	return (ant_link);
}

static char			alloc_ants(t_env *env)
{
	int	i = 0;

	while (i < env->ant_nbr)
		alloc_ant_list(env->start, i++);
}

char				parse(t_env *env) // boolean
{
	t_bool_parse	bool_parse = (t_bool_parse){0, 0}; // Ce sont des char cast en booleans
	char			*line = NULL;
	t_room_list		*last_room = NULL;

	bool_parse.step_frp = 1 << 2; // first_line_step = 1
	while (get_next_line(0, &line) && line != NULL) // Entree standard
	{
		ft_putendl(line);
		if (bool_step_frp == 4)
			get_ant_nbr(&env->ant_nbr, line, bool_parse.step_frp);
		else if (!check_comment(line) // Si ce n'est pas un commentaire
		{
			if (check_command(env, line, &bool_parse.is_start_is_end))
				(void)line;
			else if (((bool_step_frp == 2) && get_room(env, line, last_room, &bool_parse))
				|| ((bool_step_frp == 1) && get_pipe(env, line, &(bool_parse.step_frp))))
			{
				ft_strdel(&line);
				return (1);
			}
		}
		ft_strdel(&line);
	}
	if (!env->start || alloc_ants(env))
		return (1);
	return (0);
}