#include "ft_printf.h"
#include "libft/libft.h"
#include "stdlib.h"
#include "stdio.h"

char	*fill_ull_precision(unsigned long long int input, int count, char *base)
{
	char	*precisioned;
	char	*itoa;
	int		len;

	precisioned = create_width_print(count, '0');
	if (precisioned == NULL)
		return (NULL);
	itoa = ft_ulitob(input, base);
	if (itoa == NULL)
	{
		free(precisioned);
		return (NULL);
	}
	len = ft_strlen(itoa);
	ft_memcpy(&(precisioned[count - len]), itoa, len * sizeof(char));
	free(itoa);
	return (precisioned);
}

int	get_p_count(t_conv *data, long long int input, int base_size)
{
	int			count;
	int			i;
	int			is_prefixed;

	i = 1;
	is_prefixed = 0;
	if (input < 0)
		is_prefixed = 1;
	if (input > 0)
		input = -input;
	while (input <= -base_size)
	{
		input /= base_size;
		i++;
	}
	count = i + is_prefixed;
	if (data->field_width < count)
		data->field_width = count;
	printf("\n%i : %i\n", count, data->field_width);
	return (count);
}

char	*parse_specifier_p(va_list *arg, t_conv *data)
{
	unsigned long int	input;
	int					count;
	char				*print;
	char				*precisioned;

	if (data->specifier != 'p')
		return (NULL);
	input = va_arg(*arg, unsigned long int);
	count = get_p_count(data, (long long)input, 16);
	print = create_width_print(data->field_width, ' ');
	if (print == NULL)
		return (NULL);
	precisioned = fill_ull_precision(input, count, "0123456789abcdef");
	if (precisioned == NULL)
	{
		free(print);
		return (NULL);
	}
	put_prcsion(print, precisioned, data, count);
	free(precisioned);
	return (print);
}
