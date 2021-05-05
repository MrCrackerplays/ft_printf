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
