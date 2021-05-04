#include "stdio.h"
#include "ft_printf.h"
#include "libft/libft.h"

int	main(void)
{
	   printf("yes %8.4s a %d", "abcdefgh", 12);
	   printf("\n");
	ft_printf("yes %%8.4s a %d", "abcdefgh", 12);
}
