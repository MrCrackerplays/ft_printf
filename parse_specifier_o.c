#include "ft_printf.h"
#include "libft/libft.h"
#include "stdlib.h"

char	*parse_specifier_o(va_list *arg, t_conv *data)
{
	unsigned int	input;
	int				count;
	char			*print;
	char			*precisioned;

	if (data->specifier != 'o')
		return (NULL);
	input = va_arg(*arg, unsigned int);
	count = get_count(data, input, 8);
	print = create_width_print(data->field_width, ' ');
	if (print == NULL)
		return (NULL);
	precisioned = fill_u_precision(input, count, "01234567");
	if (precisioned == NULL)
	{
		free(print);
		return (NULL);
	}
	put_prcsion(print, precisioned, data, count);
	free(precisioned);
	return (print);
}