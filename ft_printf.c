#include "ft_printf.h"
#include "unistd.h"
#include "libft/libft.h"

int	ft_printf(const char *str, ...)
{
	int	position;
	int	flags;

	position = 1;
	flags = get_flags(str, &position);
	ft_putnbr_fd(position, 1);
	ft_putstr_fd(ft_strdup(str), 1);
	return (1);
}
