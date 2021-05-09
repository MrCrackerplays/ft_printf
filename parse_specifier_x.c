#include "ft_printf.h"
#include "libft/libft.h"

char	*parse_specifier_x(va_list *arg, t_conv *data)
{
	if (arg)
		data = 0;
	return (NULL);
}

char	*parse_specifier_X(va_list *arg, t_conv *data)
{
	if (data->specifier != 'X')
		return (NULL);
	return (parse_specifier_x(arg, data));
}
