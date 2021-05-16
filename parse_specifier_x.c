#include "ft_printf.h"
#include "libft/libft.h"
#include "stdlib.h"

char	*parse_specifier_x(va_list *arg, t_conv *data)
{
	unsigned int	input;
	int				count;
	char			*base;
	char			*print;
	char			*precisioned;

	if (data->specifier != 'X' && data->specifier != 'x')
		return (NULL);
	base = "0123456789abcdef";
	if (data->specifier == 'X')
		base = "0123456789ABCDEF";
	input = va_arg(*arg, unsigned int);
	count = get_count(data, input, 16);
	print = create_width_print(data->field_width, ' ');
	if (print == NULL)
		return (NULL);
	precisioned = fill_u_precision(input, count, base);
	if (precisioned == NULL)
	{
		free(print);
		return (NULL);
	}
	put_prcsion(print, precisioned, data, count);
	free(precisioned);
	return (print);
}

char	*parse_specifier_X(va_list *arg, t_conv *data)
{
	if (data->specifier != 'X')
		return (NULL);
	return (parse_specifier_x(arg, data));
}
