#include "ft_printf.h"
#include "libft/libft.h"

int	get_field_width(const char *str, int *position, va_list *args)
{
	int	width;

	width = ft_atoi(&(str[*position]));
	if (str[*position] == '*')
	{
		width = va_arg(*args, int);
		(*position)++;
	}
	else
		while(ft_isdigit(str[*position]))
			(*position)++;
	return (width);
}
