#include "ft_printf.h"
#include "libft/libft.h"
#include "stdlib.h"

char	*apply_parse(char *print, char *input, t_conv *data, int len)
{
	int	i;
	int	left;

	i = 0;
	left = is_flag_set(data->flags, '-');
	while (i < data->field_width)
	{
		if (left && i < len)
			print[i] = input[i];
		else if (!left && i >= data->field_width - len)
			print[i] = input[i - (data->field_width - len)];
		i++;
	}
	i = 0;
	return (print);
}

char	*parse_specifier_s(va_list *arg, t_conv *data)
{
	char	*input;
	char	*print;
	int		length;

	if (data->specifier != 's')
		return (NULL);
	input = va_arg(*arg, char *);
	length = ft_strlen(input);
	if (data->precision < length)
		length = data->precision;
	if (length > data->field_width)
		data->field_width = length;
	print = create_width_print(data->field_width, ' ');
	if (print == NULL)
		return (NULL);
	print = apply_parse(print, input, data, length);
	return (print);
}

char	*parse_specifier_p(va_list *arg, t_conv *data)
{
	if (arg)
		data = 0;
	return (NULL);
}

char	*parse_specifier_u(va_list *arg, t_conv *data)
{
	if (arg)
		data = 0;
	return (NULL);
}

char	*parse_specifier_X(va_list *arg, t_conv *data)
{
	if (arg)
		data = 0;
	return (NULL);
}

char	*parse_specifier_x(va_list *arg, t_conv *data)
{
	if (arg)
		data = 0;
	return (NULL);
}
