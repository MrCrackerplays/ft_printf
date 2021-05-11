#include "ft_printf.h"
#include "libft/libft.h"

char	*parse_specifier_x(va_list *arg, t_conv *data)
{
	int		input;
	char	*base;

	base = "0123456789abcdef";
	if (data->specifier == 'X')
		base = "0123456789ABCDEF";
	input = va_arg(*arg, int);
	return (ft_uitob(input, base));
}

char	*parse_specifier_X(va_list *arg, t_conv *data)
{
	if (data->specifier != 'X')
		return (NULL);
	return (parse_specifier_x(arg, data));
}
