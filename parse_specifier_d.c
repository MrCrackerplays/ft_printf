#include "ft_printf.h"
#include "libft/libft.h"
#include "stdlib.h"

int	count_digits(int number, t_conv *data)
{
	int	i;
	int	is_prefixed;

	if (number == -2147483648)
		return (11);
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

// char	*rev_copy(char *into, int input, int len_into)
// {
// 	int		len_from;
// 	char	*itoa;

// 	if (input < 0)
// 		input = -input;
// 	itoa = ft_itoa(input);
// 	if (itoa == NULL)
// 		return (NULL);
// 	len_from = ft_strlen(itoa);
// 	if (input < 0)
// 	{
// 		ft_memmove(itoa, &(itoa[1]), len_from);
// 		len_from--;
// 	}
// 	while (len_from > 0)
// 	{
// 		into[len_into - 1] = itoa[len_from - 1];
// 		len_into--;
// 		len_from--;
// 	}
// 	free(itoa);
// 	return (into);
// }

// char	*apply_precision(char *print, t_conv *data, int input)
// {
// 	int		start;
// 	char	prefix;
// 	char	*precisioned;

// 	if (data->precision == -1)
// 		data->precision = data->field_width;
// 	prefix = '\0';
// 	if (input < 0)
// 		prefix = '-';
// 	else if (is_flag_set(data->flags, ' '))
// 		prefix = ' ';
// 	else if (is_flag_set(data->flags, '+'))
// 		prefix = '+';
// 	start = prefix != '\0';
// 	precisioned = create_width_print(data->precision, '0');
// 	ft_memmove(&(print[data->field_width - data->precision]), precisioned, 3);
// 	free(precisioned);
// 	if (start)
// 		print[data->field_width - data->precision - 1] = prefix;
// 	return (print);
// }

char	*parse_specifier_d(va_list *arg, t_conv *data)
{
	int		input;
	int		count;
	char	*print;
	char	*precisioned;

	if (data->specifier != 'd')
		return (NULL);
	input = va_arg(*arg, int);
	count = count_digits(input, data);
	if (data->field_width < count)
		data->field_width = count;
	if (data->precision == -1 && is_flag_set(data->flags, '0'))
		data->precision = data->field_width;
	if ((data->precision == data->field_width) && (input < 0
		|| is_flag_set(data->flags, ' ') || is_flag_set(data->flags, '+')))
		data->precision--;
	print = create_width_print(data->field_width, ' ');
	if (print == NULL)
		return (NULL);
	// apply_precision(print, data, input);
	// rev_copy(print, input, data->field_width);
	precisioned = create_width_print(count, '0');
	ft_memmove(precisioned, ft_itoa(input), count);
	if (is_flag_set(data->flags, '-'))
		ft_memmove(print, precisioned, count);
	else
		ft_memmove(&(print[ft_strlen(print) - count]), precisioned, count);
	return (print);
}
