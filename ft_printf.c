#include "ft_printf.h"
#include "unistd.h"
#include "libft/libft.h"
#include "stdlib.h"

int	print_raw(const char *str, int position, int start)
{
	char	*print;

	print = ft_calloc(1 + position - start, sizeof(char));
	if (print == NULL)
		return (-1);
	ft_memcpy(print, &(str[start]), position - start);
	print[position - start] = '\0';
	ft_putstr_fd(print, 1);
	free(print);
	return (1);
}

t_conv	*prep_conv(va_list *arg, t_conv *data, const char *str, int *pos)
{
	data->flags = get_flags(str, pos);
	data->field_width = get_field_width(str, pos, arg);
	if (data->field_width < 0)
	{
		data->field_width *= -1;
		data->flags |= 1 << get_flag_value('-');
	}
	data->precision = get_precision(str, pos, arg);
	data->specifier = get_specifier(str, pos);
	return (data);
}

int	prnt_conv(va_list *arg, t_conv *data)
{
	static	char*(*parse[])(va_list *, t_conv *) = {parse_specifier_d,
			parse_specifier_i, parse_specifier_u, parse_specifier_x,
			parse_specifier_X, parse_specifier_c, parse_specifier_s,
			parse_specifier_p, parse_specifier_percent};
	char		*print;
	int			i;

	i = get_specifier_index(data->specifier);
	if (i < 0)
		return (-1);
	print = parse[i](arg, data);
	if (print == NULL)
		return (-1);
	ft_putstr_fd(print, 1);
	return (1);
}

int	ft_printf(const char *str, ...)
{
	int		position;
	int		start;
	t_conv	*data;
	va_list	args;

	position = 0;
	data = ft_calloc(1, sizeof(data));
	if (data == NULL)
		return (-1);
	va_start(args, str);
	while (str[position] != '\0')
	{
		start = position;
		while (str[position] != '%' && str[position] != '\0')
			position++;
		if (print_raw(str, position, start) == -1)
			return (-1);
		if (str[position] == '\0')
			break ;
		position++;
		prep_conv(&args, data, str, &position);
		if (prnt_conv(&args, data) == -1)
			return (-1);
	}
	va_end(args);
	return (1);
}
