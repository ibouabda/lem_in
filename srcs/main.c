# include "lem_in.h"

char	ant_can_move(t_ant *ant) // boolean		Check si la fourmi peut bouger sur au moins une salle autour d'elle
{
	(void)ant;
	return (1);
	return (0);
}

void	each_round(t_env *env, t_ant_list *ant_list, char *at_least_an_ant_move)
{
	t_ant		*current_ant;

	current_ant = NULL;
	while (ant_list && !env->end_round)
	{
		current_ant = ant_list->ant;
		if (current_ant
			&& ((current_ant->actual_room == env->start && ant_can_move(current_ant))
			|| (current_ant->actual_room != env->start)))
		{
			if (!current_ant->arrived) // Si la fourmi n'est pas arriver
			{
				*at_least_an_ant_move = 1;
				/* On Calcul le chemin*/
				/* On Deplace la fourmi*/
				/*On l'affiche*/
			}
			ant_list = ant_list->next;
		}
		else
			env->end_round = 1;
	}
}

static void	print_room(t_room *room)
{
	t_room_list	*links = NULL;
	t_room		*room_link = NULL;

	ft_putstr("Room name: ");
	if (room->name)
		ft_putendl(room->name);
	else
		ft_putendl("No name in room");
	links = room->link;
	while (links)
	{
		ft_putstr("Link to: ");
		room_link = links->room;
		if (room_link)
		{
			ft_putstr(room_link->name);
			ft_putstr(" | ");
		}
		links = links->next;
	}
	ft_putstr("\n\n\n");
}

static void	print_rooms(t_room_list *rooms)
{
	t_room		*room = NULL;

	while (rooms)
	{
		if ((room = rooms->room))
			print_room(rooms->room);
		else
			ft_putendl("No room in roomList");
		rooms = rooms->next;
	}
}

static void	print(t_room *start_end, const char *msg)
{
	if (!start_end)
		ft_putendl(msg);
	else
		print_room(start_end);
}

static void	print_start_end(t_room *start, t_room *end)
{
	ft_putendl(GREEN"Start room:");
	print(start, RED"There is no start room"NA);
	ft_putendl("End room:");
	print(end, RED"There is no end room"NA);
	ft_putendl(NA);
}


/******************************************/
/*	Tant que le programme n'est pas fini */
/*		Execute les rounds*/
/*			Parcourir la liste de fourmis tant que fourmi est différent de NULL ET que le round n'est pas fini*/
/*				Si la fourmi existe ET ((que la fourmi est sur la case start ET peut bouger) OU fourmi n'est pas sur la case start). */
/*					Alors Si la fourmi n'est pas encore arrivé*/
/*						-On calcul son chemin. (Grosse partie du programme). */
/*						-On la déplace. */
/*						-On affiche son déplacement. */
/*					Sinon Si aucune fourmi ne peut plus bouger*/
/*						-On termine le round*/
/*		Si aucune fourmi n'a bouger pendant le tour */
/*			C'est que l'on a terminer le programme*/
/*		Sinon on continue*/
/*****************************************/

int		main(void)
{
	t_env		env;
	t_ant_list	*ant_list;
	char		at_least_an_ant_move;

	ft_bzero(&env, sizeof(t_env));
	ant_list = NULL;
	at_least_an_ant_move = 0;

	if (parse(&env) || !env.ant_nbr) // Erreur durant le parsing
		return (1);
	ft_putendl(YELLOW"\nNombre de fourmis: ");
	ft_putnbr((int)env.ant_nbr);
	ft_putendl(NA"\n");
	// while (!env.finish)
	// {
	// 	env.end_round = 0;
	// 	ant_list = env.ants;
	// 	if (ant_list == NULL) // Si la liste de fourmi est NULL
	// 		return (1);
	// 	at_least_an_ant_move = 0;
	// 	each_round(&env, ant_list, &at_least_an_ant_move); // Un round
	// 	if (!at_least_an_ant_move || (env.end_round == 1 && ant_list == env.ants)) // Aucune fourmi ne peut bouger || La premiere fourmi ne peut pas sortir = ERREUR
	// 		env.finish = 1;
	// }
	print_rooms(env.rooms);
	print_start_end(env.start, env.end);
	erase_anthill(&env);
	return (1);
}