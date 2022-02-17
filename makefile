# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gperez <gperez@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/06 13:36:11 by gperez            #+#    #+#              #
#    Updated: 2022/02/17 22:03:46 by gperez           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem_in

FLAG = -Wall -Werror -Wextra -g

SRC =	srcs/main.c \
		srcs/parser.c \
		srcs/parse_room.c \
		srcs/parse_pipe.c \
		srcs/erase_anthill.c \
		srcs/alloc_ants.c \
		srcs/ft_strnew_cpy.c \

NC = \033[0m
BOLD =\033[1m
DIM =\033[2m
ITALIC =\033[3m
UNDER =\033[4m
BLINK =\033[5m

RS_BO = \033[21m
RS_D = \033[22m
RS_I = \033[23m
RS_U =\033[24m
RS_BL = \033[25m

WHITE = \033[37m
BLUE = \033[38;5;37m
CYAN = \033[38;5;117m
GREEN = \033[38;5;120m
MAGENTA = \033[38;5;135m
RED = \033[38;5;203m

COLOR1 = \033[38;5;75m
COLOR2 = \033[38;5;178m

LIB_L = libft/libft.a

LIBS_H =	libft/incl \
			incl \

LIBS = $(addprefix -I,$(LIBS_H))

INC =	incl/lem_in.h \

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(LIB_L) :
	@make -C libft

$(NAME) : $(LIB_L) $(OBJ)
	@g++ $(FLAG) $^ -o $(NAME)
	@printf "$(BOLD)$(COLOR1)%20s : $(RS_BL)$(RS_BO)$(GREEN)succesfuly made!$(NC)%20s\n" $(NAME)

%.o : %.c $(INC)
	@printf "$(BOLD)$(COLOR1)%20s : $(RS_BO)$(COLOR2)%20s$(WHITE) ...$(NC)" $(NAME) $(<F)
	@gcc $(FLAG) $(LIBS) -o $@ -c $<
	@printf "\r"

clean :
	@make -C libft clean
	@/bin/rm -rf srcs/*.o

fclean : clean
	@/bin/rm -rf $(NAME)
	@/bin/rm -rf $(LIB_L)

re : fclean all