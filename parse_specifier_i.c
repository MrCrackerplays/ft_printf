#include "ft_printf.h"
#include "stddef.h"

char	*parse_specifier_i(va_list *arg, t_conv *data)
{
	data->specifier = 'd';
	return (parse_specifier_d(arg, data));
}
