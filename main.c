#include "stdio.h"
#include "ft_printf.h"
#include "libft/libft.h"

int	main(void)
{
	   printf("%%yes %08.3dc a %-8.3d b %8d", -13, -12, -11);
	   printf("\n");
	ft_printf("%%yes %08.3dc a %-8.3d b %8d", -13, -12, -11);
}
