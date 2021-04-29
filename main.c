#include "stdio.h"
#include "ft_printf.h"
#include "libft/libft.h"

int	main(void)
{
	   printf("yes %f a %d", 111.234, 12);
	   printf("\n");
	ft_printf("%--0-e %d a % s", 11, 12);
}
