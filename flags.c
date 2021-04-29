#include "ft_printf.h"
#include "libft/libft.h"

int	get_flag_value(char c)
{
	int	i;

	i = 0;
	while (g_flags[i] && g_flags[i] != c)
		i++;
	if (g_flags[i] == '\0')
		return (-1);
	return (i);
}

int	get_flags(const char *str, int *position)
{
	int		flags;
	char	character[2];

	flags = 0;
	character[1] = '\0';
	character[0] = str[*position];
	while (ft_strnstr(g_flags, &character[0], 50))
	{
		flags |= 1 << get_flag_value(character[0]);
		(*position)++;
		character[0] = str[*position];
	}
	return (flags);
}
