#include "ft_printf.h"
#include "libft/libft.h"

int	get_specifier_index(char c)
{
	int	i;

	i = 0;
	while (g_specifiers[i] && g_specifiers[i] != c)
		i++;
	if (g_flags[i] == '\0')
		return (-1);
	return (i);
}

char	get_specifier(const char *str, int *position)
{
	char	character;

	if (ft_strnstr(g_specifiers, str[*position], 50) == 1)
		return ('\0');
	character = str[*position];
	(*position)++;
	return (character);
}
