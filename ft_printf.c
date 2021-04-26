#include "ft_printf.h"
#include "unistd.h"
#include "libft/libft.h"

int ft_printf(const char *str, ...)
{
	write(1, str, ft_strlen(str));
	return (1);
}