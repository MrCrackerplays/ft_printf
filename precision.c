#include "ft_printf.h"
#include "libft/libft.h"

int	get_precision(const char *str, int *position, va_list *args)
{
	int	precision;

	if (str[*position] != '.')
		return (-1); // = conversion specifier dependant
	(*position)++;
	precision = ft_atoi(&(str[*position]));
	if (str[*position] == '*')
	{
		precision = va_arg(*args, int);
		(*position)++;
	}
	else
		while(ft_isdigit(str[*position]))
			(*position)++;
	return (precision);
}
