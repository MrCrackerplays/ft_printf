#include "ft_printf.h"
#include "libft/libft.h"

char	*parse_specifier_s(va_list *arg, t_conv *data)
{
	char	*input;
	char	*print;
	int		length;

	input = va_arg(*arg, char *);
	if (input == NULL)
		input = "(null)";
	length = ft_strlen(input);
	if (data-> precision != -1 && data->precision < length)
		length = data->precision;
	if (length > data->field_width)
		data->field_width = length;
	print = create_width_print(data->field_width, ' ');
	if (print == NULL)
		return (NULL);
	put_prcn(print, input, data, length);
	return (print);
}
