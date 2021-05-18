#include "ft_printf.h"
#include "libft/libft.h"

t_length_mod	get_length_mod(const char *str, int *position)
{
	t_length_mod	mod;
	char			*ch;

	ch = ft_strnstr(g_length_mods, &(str[*position]), 50);
	if (!ch)
		return (none);
	(*position)++;
	if (*ch == str[*position] && (str - 1) != ft_strrchr(g_length_mods, *ch))
	{
		if (*ch == 'h')
			return (hh);
		return (ll);
	}
	mod = (t_length_mod)(g_length_mods - ch);
	return (mod);
}
