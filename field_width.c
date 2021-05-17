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

int	count_digits(long int number, t_conv *data, int base_size)
{
	int	i;
	int	is_prefixed;

	if (number == 0 && data->precision == 0)
		return (0);
	i = 1;
	is_prefixed = 0;
	if (number < 0 || is_flag_set(data->flags, ' ')
		|| is_flag_set(data->flags, '+'))
		is_prefixed = 1;
	if (number > 0)
		number = -number;
	while (number <= -base_size)
	{
		number /= base_size;
		i++;
	}
	if (data->precision == -1 && !is_flag_set(data->flags, '-')
		&& is_flag_set(data->flags, '0'))
		data->precision = data->field_width - is_prefixed;
	if (i < data->precision)
		return (data->precision + is_prefixed);
	return (i + is_prefixed);
}

int	get_count(t_conv *data, long int input, int base_size)
{
	int	count;

	count = count_digits(input, data, base_size);
	if (data->field_width < count)
		data->field_width = count;
	if ((data->precision == data->field_width) && (input < 0
			|| is_flag_set(data->flags, ' ') || is_flag_set(data->flags, '+')))
		data->precision--;
	return (count);
}
