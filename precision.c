#include "ft_printf.h"
#include "libft/libft.h"

int	get_precision(const char *str, int *position, va_list *args)
{
	int	precision;

	if (str[*position] != '.')
		return (-1);
	(*position)++;
	precision = 0;
	if (str[*position] == '*')
	{
		precision = va_arg(*args, int);
		if (precision < 0)
			precision = -1;
		(*position)++;
	}
	else if (ft_isdigit(str[*position]))
	{
		precision = ft_atoi(&(str[*position]));
		while (ft_isdigit(str[*position]))
			(*position)++;
	}
	return (precision);
}
