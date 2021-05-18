#include "ft_printf.h"
#include "stddef.h"

char	*parse_specifier_c(va_list *arg, t_conv *data)
{
	unsigned char	input;
	char			*print;

	input = (unsigned char) va_arg(*arg, int);
	if (data->field_width < 1)
		data->field_width = 1;
	print = create_width_print(data->field_width, ' ');
	if (print == NULL)
		return (NULL);
	if (is_flag_set(data->flags, '-'))
		print[0] = input;
	else
		print[data->field_width - 1] = input;
	return (print);
}
