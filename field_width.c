#include "ft_printf.h"
#include "libft/libft.h"
#include "stdlib.h"

int	get_field_width(const char *str, int *position, va_list *args)
{
	int	width;

	if (str[*position] == '*')
	{
		width = va_arg(*args, int);
		(*position)++;
	}
	else
	{
		width = ft_atoi(&(str[*position]));
		while (ft_isdigit(str[*position]))
			(*position)++;
	}
	return (width);
}

char	*create_width_print(int width, char fill)
{
	char	*ret;
	int		i;

	ret = malloc(sizeof(char) * (width + 1));
	if (ret == NULL)
		return (NULL);
	i = 0;
	while (i < width)
	{
		ret[i] = fill;
		i++;
	}
	ret[width] = '\0';
	return (ret);
}

int	count_digits(long int number, t_conv *data, int base_size, int prefix)
{
	int	i;

	i = 1;
	if (number > 0)
		number = -number;
	while (number <= -base_size)
	{
		number /= base_size;
		i++;
	}
	if (data->precision == -1 && !is_flag_set(data->flags, '-')
		&& is_flag_set(data->flags, '0'))
		data->precision = data->field_width - prefix;
	if (i < data->precision)
		return (data->precision + prefix);
	return (i + prefix);
}

int	get_count(t_conv *data, long int input, int base_size)
{
	int	count;
	int	prefix;

	prefix = 0;
	if (input < 0 || is_flag_set(data->flags, ' ')
		|| is_flag_set(data->flags, '+'))
		prefix = 1;
	if ((data->specifier == 'x' || data->specifier == 'X')
		&& (is_flag_set(data->flags, '#')))
		prefix = 2;
	if (input == 0 && data->precision == 0)
		count = is_flag_set(data->flags, '+') || is_flag_set(data->flags, ' ');
	else
		count = count_digits(input, data, base_size, prefix);
	if (data->field_width < count)
		data->field_width = count;
	if ((data->precision == data->field_width) && (input < 0
			|| is_flag_set(data->flags, ' ') || is_flag_set(data->flags, '+')))
		data->precision--;
	return (count);
}
