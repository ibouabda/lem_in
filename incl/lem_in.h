#ifndef __LEM_IN_H__
# define __LEM_IN_H__

# include "libft.h"
# include <stdio.h>

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
	t_room				*room;
	struct s_room_list	*next;
}						t_room_list;

typedef struct			s_ant_list
{
	t_ant				*ant;
	struct s_ant_list	*next;
}						t_ant_list;

typedef struct			s_env
{
	t_room_list			*rooms; // Pour ranger et parcourir linéairement les salles.
	t_room				*start; // Pour faire les calculs de chemins.
	t_room				*end; // Pour faire les calculs de chemins.
	t_ant_list			*ants; // Liste de fourmis.
	unsigned int		ant_nbr;
	char				finish; // Soit 0 soit 1 (met fin au programme)
	char				end_round; // Soit 0 soit 1 (met fin au programme)
}						t_env;

char					*ft_strnew_cpy(char *str);

typedef struct			s_bool_parse
{
	char	step_frp;			// 0	|	first_line_step	|	room_step	|	pipe_step
	char	is_start_is_end;	// 0	|			0 		|	is_start	|	is_end
}						t_bool_parse;

char					parse(t_env *env);
char					get_room(t_env *env, char *line, t_room_list *last_room,
	t_bool_parse *bool_parse);
char					get_pipe(t_env *env, char *line);
char					alloc_ants(t_env *env);

char					ant_can_move(t_ant *ant);
void					each_round(t_env *env, t_ant_list *ant_list, char *at_least_an_ant_move);

void					erase_anthill(t_env *env);
#endif