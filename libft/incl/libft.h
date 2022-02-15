/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouabda <ibouabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 15:22:12 by ibouabda          #+#    #+#             */
/*   Updated: 2020/02/01 18:53:23 by ibouabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H

# define LIBFT_H
# define BUFF_SIZE 4096
# include <string.h>
# include <stdlib.h>
# include <unistd.h>

typedef	struct		s_prlist
{
	char			*content;
	int				fd;
	struct s_prlist	*next;
	struct s_prlist	*prev;
}					t_prlist;

typedef	struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_3dpoint
{
	int x;
	int y;
	int z;
}					t_3dpoint;

typedef struct		s_point
{
	int x;
	int y;
	int h;
}					t_point;

typedef struct		s_dpoint
{
	double x;
	double y;
}					t_dpoint;

typedef struct		s_fpoint
{
	float x;
	float y;
}					t_fpoint;

int					ft_atoi(const char *str);
void				ft_bzero(void *src, size_t n);
void				*ft_memchr(const void *src, int c, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t len);
void				*ft_memset(void *src, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
char				*ft_strcat(char *dest, const char *src);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strcpy(char *dest, const char *src);
size_t				ft_strlen(const char *str);
char				*ft_strncat(char *dest, const char *src, size_t nb);
int					ft_strncmp(const char *src, const char *dest, size_t n);
char				*ft_strncpy(char *dest, const char *src, size_t n);
char				*ft_strstr(const char *str, const char *to_find);
char				*ft_strnstr(const char *str, const char *to_find, size_t n);
char				*ft_strdup(const char *s1);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
char				*ft_strchr(const char *src, int c);
char				*ft_strrchr(const char *src, int c);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
size_t				ft_lstlen(t_list *lst);
void				ft_lstaddend(t_list **alst, t_list *new);
t_list				*ft_lstmanynew(size_t lst_size, void const *content,\
size_t content_size);
void				ft_putstrlst(t_list *m);
void				ft_lstaddafter(t_list **alst, t_list *new);
t_list				*ft_lstnewstr(char *content, size_t content_size);
void				ft_lstdellink(t_list *m);
char				**ft_2dstrnew(size_t size);
char				***ft_3dstrnew(size_t size);
int					ft_3dstrin(char ***s1, char ***s2);
void				ft_3dputstr(char ***tetrim);
int					ft_2dstrcmp(char **s1, char **s2);
int					ft_2dstrlen(char **str);
int					ft_3dstrlen(char ***str);
int					ft_sqrt(int nb);
int					ft_sqrt_aprox(int nb);
void				ft_2dputstr(char **tetrim);
void				ft_2dstrdel(char **as);
void				ft_3dstrdel(char ***tetrim);
int					ft_size_t_del(size_t *as);
int					ft_countnumbers(int nb);
char				*ft_itoa_base(int nb, int base);
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstdellink(t_list *m);
void				ft_lstdelm(t_list **alst);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_putdouble(double n, int *i);
char				*ft_strchar(int nb, char c);
char				*ft_strrev(char *str);
t_list				*ft_lstnewc(void *content, size_t c);
char				*ft_itoa_base_maj(int nb, int base);
void				ft_putnbr_count(int n, int *i);
int					ft_strnstrdup(char *str, char *to_find,\
size_t n, char **stock);
char				*ft_str2chr(char *src, char *to_find);
t_list				*ft_lstnewd(void *content, size_t content_size);
void				ft_lstdelstr(t_list *alst);
int					**ft_2dintnew(size_t size);
int					*ft_intnew(int size);
void				ft_2dputtabint(int **tab, int sizeline);
void				ft_puttabint(int *tab, int size);
void				ft_2dmemdel(void **as);
t_point				*ft_t_pointnew(int x, int y);
void				t_3dpointval(t_3dpoint *point, int x, int y, int z);
void				ft_putnbrl(int n);
void				ft_memswitch(void **a, void **b);
int					get_next_line(const int fd, char **line);
int					*ft_intnew_clean(int size);
int					ft_2dstrchr(char **str, char c, t_fpoint *a);
int					ft_abs(int value);
int					ft_bool(int value);

#endif
