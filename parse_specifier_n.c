#include "ft_printf.h"
#include "stdlib.h"

char	*parse_specifier_n(va_list *arg, t_conv *data)
{
	int		*input;
	char	*print;

	input = va_arg(*arg, int *);
	*input = data->read;
	print = malloc(1 * sizeof(char));
	if (print == NULL)
		return (NULL);
	print[0] = '\0';
	return (print);
}
