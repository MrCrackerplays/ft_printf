#include "ft_printf.h"
#include "libft/libft.h"
#include "stdlib.h"

char	*fill_precision(int input, int count, t_conv *data, char *base)
{
	char	*precisioned;
	char	*itoa;
	int		len;

	precisioned = create_width_print(count, '0');
	if (precisioned == NULL)
		return (NULL);
	if (input < 0)
		itoa = ft_uitob(-((unsigned int)input), base);
	else
		itoa = ft_uitob((unsigned int)input, base);
	if (itoa == NULL)
		free(precisioned);
	if (itoa == NULL)
		return (NULL);
	len = ft_strlen(itoa);
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

char	*parse_specifier_d(va_list *arg, t_conv *data)
{
	int		input;
	int		count;
	char	*print;
	char	*precisioned;

	if (data->specifier != 'd')
		return (NULL);
	input = va_arg(*arg, int);
	count = get_count(data, input, 10);
	print = create_width_print(data->field_width, ' ');
	if (print == NULL)
		return (NULL);
	precisioned = fill_precision(input, count, data, "0123456789");
	if (precisioned == NULL)
	{
		free(print);
		return (NULL);
	}
	put_prcsion(print, precisioned, data, count);
	free(precisioned);
	return (print);
}
