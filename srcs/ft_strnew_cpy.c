# include "lem_in.h"

char	*ft_strnew_cpy(char *str)
{
	char	*new_str = NULL;

	if (!(new_str = ft_strnew(ft_strlen(str))))
		return (NULL);
	ft_strcpy(new_str, str);
	return (new_str);
}