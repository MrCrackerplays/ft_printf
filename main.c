#include "stdio.h"
#include "ft_printf.h"
#include "libft/libft.h"

int	main(void)
{
	int	amount;

	ft_printf("%d", -50);
	   printf(".%%syes %03.5dc a %-8.3d b %8d c %08d d %d", -130, -12, -11, -10, -1);
	   printf("\n");
	amount = ft_printf(".%%syes %03.5dc a %-8.3d b %8d c %08d d %d", -130, -12, -11, -10, -1);
	printf("\n%d\n", amount);
}
