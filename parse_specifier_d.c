#include "ft_printf.h"
#include "libft/libft.h"
#include "stdlib.h"
#include "stdio.h"

int	count_digits(int number, t_conv *data)
{
	int	i;
	int	is_prefixed;

	if (number == -2147483648)
		return (11);
	if (number == 0 && data->precision == 0)
		return (0);
	i = 1;
	is_prefixed = 0;
	if (number < 0 || is_flag_set(data->flags, ' ')
		|| is_flag_set(data->flags, '+'))
		is_prefixed = 1;
	if (number < 0)
		number = -number;
	while (number >= 10)
	{
		number /= 10;
		i++;
	}
	if (i < data->precision)
		return (data->precision + is_prefixed);
	return (i + is_prefixed);
}

char	*fill_precision(int input, int count, t_conv *data)
{
	char	*precisioned;
	char	*itoa;
	int		len;

	precisioned = create_width_print(count, '0');
	if (precisioned == NULL)
		return (NULL);
	itoa = ft_itoa(input);
	if (itoa == NULL)
		return (NULL);
	len = ft_strlen(itoa);
	if (input < 0)
	{
		len--;
		ft_memmove(itoa, &(itoa[1]), len * sizeof(char));
	}
	ft_memcpy(&(precisioned[count - len]), itoa, len * sizeof(char));
	free(itoa);
	if (input < 0)
		precisioned[0] = '-';
	else if (is_flag_set(data->flags, '+'))
		precisioned[0] = '+';
	else if (is_flag_set(data->flags, ' '))
		precisioned[0] = ' ';
	return (precisioned);
}

void	put_prcsion(char *print, const char *prcsion, t_conv *data, int count)
{
	if (is_flag_set(data->flags, '-'))
		ft_memmove(print, prcsion, count);
	else
		ft_memmove(&(print[ft_strlen(print) - count]), prcsion, count);
}

char	*parse_specifier_d(va_list *arg, t_conv *data)
{
	int		input;
	int		count;
	char	*print;
	char	*precisioned;

	if (data->specifier != 'd')
		return (NULL);
	input = va_arg(*arg, int);
	if (data->precision == -1 && !is_flag_set(data->flags, '-')
		&& is_flag_set(data->flags, '0'))
		data->precision = data->field_width;
	count = count_digits(input, data);
	if (data->field_width < count)
		data->field_width = count;
	if ((data->precision == data->field_width) && (input < 0
			|| is_flag_set(data->flags, ' ') || is_flag_set(data->flags, '+')))
		data->precision--;
	print = create_width_print(data->field_width, ' ');
	if (print == NULL)
		return (NULL);
	precisioned = fill_precision(input, count, data);
	if (precisioned == NULL)
		return (NULL);
	put_prcsion(print, precisioned, data, count);
	return (print);
}
