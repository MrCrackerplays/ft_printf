#include "ft_printf.h"
#include "libft/libft.h"
#include "stdlib.h"

int	count_digits(int number, int flags)
{
	int	i;

	if (number == -2147483648)
		return (11);
	if (number < 0 || is_flag_set(flags, ' ') || is_flag_set(flags, '+'))
		i = 2;
	else
		i = 1;
	if (number < 0)
		number = -number;
	while (number >= 10)
	{
		number /= 10;
		i++;
	}
	return (i);
}

char	*rev_copy(char *into, int input, int len_into)
{
	int		len_from;
	char	*itoa;

	if (input < 0)
		input = -input;
	itoa = ft_itoa(input);
	if (itoa == NULL)
		return (NULL);
	len_from = ft_strlen(itoa);
	if (input < 0)
	{
		ft_memmove(itoa, &(itoa[1]), len_from);
		len_from--;
	}
	while (len_from > 0)
	{
		into[len_into - 1] = itoa[len_from - 1];
		len_into--;
		len_from--;
	}
	free(itoa);
	return (into);
}

char	*parse_specifier_d(va_list *arg, t_conv *data)
{
	int		input;
	int		count;
	char	*print;

	if (data->specifier != 'd')
		return (NULL);
	input = va_arg(*arg, int);
	count = count_digits(input, data->flags);
	if (data->field_width < count)
		data->field_width = count;
	if (is_flag_set(data->flags, '0') && data->precision == -1)
		print = create_width_print(data->field_width, '0');
	else
		print = create_width_print(data->field_width, ' ');
	if (print == NULL)
		return (NULL);
	rev_copy(print, input, data->field_width);
	if (input < 0)
		print[0] = '-';
	else if (is_flag_set(data->flags, ' '))
		print[0] = ' ';
	else if (is_flag_set(data->flags, '+'))
		print[0] = '+';
	return (print);
}
