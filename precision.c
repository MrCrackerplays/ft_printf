#include "ft_printf.h"
#include "libft/libft.h"
#include "stdlib.h"

int	get_precision(const char *str, int *position, va_list *args)
{
	int	precision;

	if (str[*position] != '.')
		return (-1);
	(*position)++;
	precision = 0;
	if (str[*position] == '*')
	{
		precision = va_arg(*args, int);
		if (precision < 0)
			precision = -1;
		(*position)++;
	}
	else if (ft_isdigit(str[*position]))
	{
		precision = ft_atoi(&(str[*position]));
		while (ft_isdigit(str[*position]))
			(*position)++;
	}
	return (precision);
}

char	*fill_u_precision(unsigned int input, int count, char *base)
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

void	put_prcsion(char *print, const char *prcsion, t_conv *data, int count)
{
	if (is_flag_set(data->flags, '-'))
		ft_memmove(print, prcsion, count * sizeof(char));
	else
		ft_memmove(&(print[ft_strlen(print) - count]), prcsion, count
			* sizeof(char));
}
