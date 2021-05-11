#include "stdio.h"
#include "ft_printf.h"
#include "libft/libft.h"

void	test_i(int *arr, int size)
{
	int	i;

	i = 0;
	printf("== BASIC ==\n");
	while (i < size)
	{
		ft_printf("%d == ", arr[i]);
		   printf("%d\n", arr[i]);
		i++;
	}
	i = 0;
	printf("== PRECISION ==\n");
	while (i < size)
	{
		ft_printf("%.5i == ", arr[i]);
		   printf("%.5i\n", arr[i]);
		i++;
	}
	i = 0;
	printf("== FIELD WIDTH ==\n");
	while (i < size)
	{
		ft_printf("%5i == ", arr[i]);
		   printf("%5i\n", arr[i]);
		i++;
	}
	i = 0;
	printf("== P > W ==\n");
	while (i < size)
	{
		ft_printf("%4.7i == ", arr[i]);
		   printf("%4.7i\n", arr[i]);
		i++;
	}
	i = 0;
	printf("== P < W ==\n");
	while (i < size)
	{
		ft_printf("%7.4i == ", arr[i]);
		   printf("%7.4i\n", arr[i]);
		i++;
	}
	i = 0;
	printf("== P = W ==\n");
	while (i < size)
	{
		ft_printf("%4.4i == ", arr[i]);
		   printf("%4.4i\n", arr[i]);
		i++;
	}
	i = 0;
	printf("== 0P ==\n");
	while (i < size)
	{
		ft_printf("%.0i == ", arr[i]);
		   printf("%.0i\n", arr[i]);
		i++;
	}
	i = 0;
	printf("== LEFT ==\n");
	while (i < size)
	{
		ft_printf("%*i == ", -4, arr[i]);
		   printf("%*i\n", -4, arr[i]);
		i++;
	}
	i = 0;
	printf("== ZERO ==\n");
	while (i < size)
	{
		ft_printf("%04.7i == ", arr[i]);
		   printf("%04.7i\n", arr[i]);
		i++;
	}
}

void	test_c(void)
{

}

int	main(void)
{
	// int	amount;
	// int	arr[7] = {1, -3, 2147483647, (int)2147483648, 69, -21, 1337};
	// printf("\x1b[38;5;200m _       _\n");
	// printf("(_)_ __ | |_ ___  __ _  ___ _ __ ___ \n");
	// printf("| | '_ \\| __/ _ \\/ _` |/ _ \\ '__/ __|\n");
	// printf("| | | | | ||  __/ (_| |  __/ |  \\__ \\\n");
	// printf("|_|_| |_|\\__\\___|\\__, |\\___|_|  |___/\n");
	// printf("                 |___/               \n\x1b[0m");
	// test_i(&arr[0], 7);
	ft_printf("%x", 1337);

	// amount = ft_printf("%d", -50);
	//    printf("\n");
	//    printf(".%%syes %03.5dc a %-8.3d b %8d c %08d d %d", -130, -12, -11, 10, 10);
	//    printf("\n");
	// ft_printf(".%%syes %03.5dc a %-8.3d b %8d c %08d d %d", -130, -12, -11, 10, 10);
	// printf("\n%d\n", amount);
	// printf("%#05X", 11);
}
