# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ibouabda <ibouabda@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 21:31:16 by ibouabda          #+#    #+#              #
#    Updated: 2020/02/08 13:35:37 by ibouabda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### COMPILATION ###

CC = gcc

CFLAGS = -Wall -Werror -Wextra

### EXECUTABLE ###

NAME = libft

### INCLUDES ###

SRC_PATH = srcs
OBJ_PATH = objs
HEADER = incl
SRC_NAME = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isprint.c ft_isdigit.c \
		ft_lstadd.c ft_lstdel.c ft_lstdelone.c ft_lstiter.c ft_memalloc.c \
		ft_lstmap.c ft_lstnew.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memdel.c \
		ft_memmove.c ft_memset.c ft_itoa.c ft_putchar_fd.c ft_putendl.c \
		ft_putendl_fd.c ft_memccpy.c ft_putchar.c ft_putnbr.c ft_putstr_fd.c \
		ft_putstr.c ft_putnbr_fd.c ft_strcat.c ft_strclr.c ft_strchr.c ft_lstnewstr.c\
		ft_strcpy.c ft_strdel.c ft_strdup.c ft_strequ.c ft_strcmp.c ft_striter.c \
		ft_striteri.c ft_strlen.c ft_strjoin.c ft_strlcat.c ft_strmap.c ft_isalnum.c \
		ft_strncat.c ft_strncpy.c ft_strmapi.c ft_strncmp.c ft_strnequ.c ft_3dstrnew.c\
		ft_strnew.c ft_strrchr.c ft_strnstr.c ft_strstr.c ft_strsub.c ft_isalpha.c \
		ft_strtrim.c ft_tolower.c ft_toupper.c ft_lstlen.c ft_lstmanynew.c ft_2dstrnew.c\
		ft_strsplit.c ft_isascii.c ft_lstaddafter.c ft_lstaddend.c ft_putstrlst.c\
		ft_3dstrin.c ft_2dstrcmp.c ft_3dputstr.c ft_2dstrlen.c ft_3dstrlen.c ft_sqrt.c\
		ft_2dputstr.c ft_2dstrdel.c ft_sqrt_aprox.c ft_3dstrdel.c ft_size_t_del.c\
		ft_countnumbers.c ft_itoa_base.c ft_itoa_base_maj.c ft_lstadd.c ft_lstdellink.c\
		ft_lstdelm.c ft_lstnewc.c ft_putdouble.c ft_strchar.c ft_strrev.c ft_itoa_base_maj.c\
		ft_putnbr_count.c ft_strnstrdup.c ft_str2chr.c ft_lstnewd.c ft_lstdelstr.c\
		ft_2dintnew.c ft_intnew.c ft_puttabint.c ft_2dputtabint.c ft_2dmemdel.c t_3dpointval.c\
		ft_putnbrl.c ft_memswitch.c get_next_line.c ft_intnew_clean.c ft_2dstrchr.c ft_bool.c\
		ft_abs.c

### OBJECTS ###

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJS = $(addprefix $(OBJ_PATH)/,$(SRC_NAME:.c=.o))

### COLORS ###

NOC         = \033[0m
BOLD        = \033[1m
UNDERLINE   = \033[4m
BLACK       = \033[1;30m
RED         = \033[1;31m
GREEN       = \033[1;32m
YELLOW      = \033[1;33m
BLUE        = \033[1;34m
VIOLET      = \033[1;35m
CYAN        = \033[1;36m
WHITE       = \033[1;37m


all: tmp $(NAME)

$(NAME): $(OBJS)
	@echo "$(YELLOW)Checking libft files ...$(NOC)"
	@ar rc $(NAME).a $(OBJS)
	@ranlib $(NAME).a
	@echo "$(YELLOW)Libft successfully compiled !$(NOC)"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(HEADER)/$(NAME).h
	@$(CC) $(CFLAGS) -I $(HEADER) -c -o $@ $<

tmp:
	@mkdir -p $(OBJ_PATH)

clean:
	@rm -rf $(OBJ_PATH)

fclean: clean
	@rm -f $(NAME).a

re: fclean all

.phony : all clean fclean re