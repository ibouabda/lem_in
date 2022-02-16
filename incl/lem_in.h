#ifndef __LEM_IN_H__
# define __LEM_IN_H__

# include "libft.h"

typedef struct			s_ant
{
	int					id;
	char				arrived; // 0 non 1 oui
	struct s_room 		*actual_room;
}						t_ant;

typedef struct			s_room
{
	char				*name;
	int					coord_x;
	int					coord_y;
	struct s_room_list	*link;
	t_ant				*occupied_ant;
}						t_room;

typedef struct			s_room_list
{
	char				*name;
	t_room				*room;
	struct s_room_list	*next;
}						t_room_list;

typedef struct			s_ant_list
{
	int					id;
	t_ant				*ant;
	struct s_ant_list	*next;
}						t_ant_list;

typedef struct			s_env
{
	t_room_list			*rooms; // Pour ranger et parcourir linéairement les salles.
	t_room				*start; // Pour faire les calculs de chemins.
	t_room				*end; // Pour faire les calculs de chemins.
	t_ant_list			*ants; // Liste de fourmis.
	char				finish; // Soit 0 soit 1 (met fin au programme)
	char				end_round; // Soit 0 soit 1 (met fin au programme)
}						t_env;

char					parse(t_env *env);
char					ant_can_move(t_ant *ant);
void					each_round(t_env *env, t_ant_list *ant_list, char *at_least_an_ant_move);
#endif