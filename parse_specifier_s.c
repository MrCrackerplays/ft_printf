#include "ft_printf.h"
#include "libft/libft.h"
#include "stdlib.h"

char	*parse_specifier_s(va_list *arg, t_conv *data)
{
	char	*input;
	char	*print;
	int		length;

	if (data->specifier != 's')
		return (NULL);
	input = va_arg(*arg, char *);
	if (input == NULL)
	{
		data->field_width = 6;
		print = create_width_print(data->field_width, ' ');
		put_prcsion(print, "(null)", data, data->field_width);
		return (print);
	}
	length = ft_strlen(input);
	if (data-> precision != -1 && data->precision < length)
		length = data->precision;
	if (length > data->field_width)
		data->field_width = length;
	print = create_width_print(data->field_width, ' ');
	if (print == NULL)
		return (NULL);
	put_prcsion(print, input, data, length);
	return (print);
}
