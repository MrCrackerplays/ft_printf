#include "ft_printf.h"
#include "libft/libft.h"

char	*create_precision(t_conv *data, int input)
{
	if (data || input)
		;
	return (NULL);
}

char	*put_precision(char *print, char *prescioned, t_conv *data)
{
	if (print || prescioned || data)
		;
	return (NULL);
}

char	*parse_specifier_x(va_list *arg, t_conv *data)
{
	int		input;
	char	*base;
	char	*print;
	char	*precisioned;

	if (data->specifier != 'X' && data->specifier != 'x')
		return (NULL);
	base = "0123456789abcdef";
	if (data->specifier == 'X')
		base = "0123456789ABCDEF";
	input = va_arg(*arg, int);
	print = create_width_print(data->field_width, ' ');
	precisioned = create_precision(data, input);
	put_precision(print, precisioned, data);
	// print = ft_uitob(input, base);
	return (print);
}

char	*parse_specifier_X(va_list *arg, t_conv *data)
{
	if (data->specifier != 'X')
		return (NULL);
	return (parse_specifier_x(arg, data));
}
