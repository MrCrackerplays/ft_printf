#include "ft_printf.h"
#include "stddef.h"
#include "stdlib.h"

char	*parse_specifier_percent(va_list *arg, t_conv *data)
{
	char	*print;

	if (arg || data)
		;
	print = malloc(sizeof(char) * 2);
	if (print == NULL)
		return (NULL);
	print[0] = '%';
	print[1] = '\0';
	return (print);
}
