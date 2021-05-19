#include "ft_printf.h"
#include "stdlib.h"

char	*parse_specifier_n(va_list *arg, t_conv *data)
{
	char	*print;

	if (data->length_mod == h)
		*(va_arg(*arg, short *)) = data->read;
	else if (data->length_mod == hh)
		*(va_arg(*arg, char *)) = data->read;
	else if (data->length_mod == l)
		*(va_arg(*arg, long *)) = data->read;
	else if (data->length_mod == ll)
		*(va_arg(*arg, long long *)) = data->read;
	else
		*(va_arg(*arg, int *)) = data->read;
	print = malloc(1 * sizeof(char));
	if (print == NULL)
		return (NULL);
	print[0] = '\0';
	return (print);
}
