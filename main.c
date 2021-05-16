#include "stdio.h"
#include "ft_printf.h"
#include "libft/libft.h"

void	test_i(int *arr, int size)
{
	int	i;

	printf("\x1b[38;5;200m _       _\n");
	printf("(_)_ __ | |_ ___  __ _  ___ _ __ ___ \n");
	printf("| | '_ \\| __/ _ \\/ _` |/ _ \\ '__/ __|\n");
	printf("| | | | | ||  __/ (_| |  __/ |  \\__ \\\n");
	printf("|_|_| |_|\\__\\___|\\__, |\\___|_|  |___/\n");
	printf("                 |___/               \x1b[0m\n");
	i = 0;
	printf("== BASIC ==\n");
	while (i <= size)
	{
		ft_printf("|%d| == ", arr[i]);
		   printf("|%d|\n", arr[i]);
		i++;
	}
	i = 0;
	printf("== PRECISION ==\n");
	while (i <= size)
	{
		ft_printf("|%.5i| == ", arr[i]);
		   printf("|%.5i|\n", arr[i]);
		i++;
	}
	i = 0;
	printf("== FIELD WIDTH ==\n");
	while (i <= size)
	{
		ft_printf("|%5i| == ", arr[i]);
		   printf("|%5i|\n", arr[i]);
		i++;
	}
	i = 0;
	printf("== P > W ==\n");
	while (i <= size)
	{
		ft_printf("|%4.7i| == ", arr[i]);
		   printf("|%4.7i|\n", arr[i]);
		i++;
	}
	i = 0;
	printf("== P < W ==\n");
	while (i <= size)
	{
		ft_printf("|%7.4i| == ", arr[i]);
		   printf("|%7.4i|\n", arr[i]);
		i++;
	}
	i = 0;
	printf("== P = W ==\n");
	while (i <= size)
	{
		ft_printf("|%4.4i| == ", arr[i]);
		   printf("|%4.4i|\n", arr[i]);
		i++;
	}
	i = 0;
	printf("== 0P ==\n");
	while (i <= size)
	{
		ft_printf("|%.0i| == ", arr[i]);
		   printf("|%.0i|\n", arr[i]);
		i++;
	}
	i = 0;
	printf("== LEFT ==\n");
	while (i <= size)
	{
		ft_printf("|%*i| == ", -4, arr[i]);
		   printf("|%*i|\n", -4, arr[i]);
		i++;
	}
	i = 0;
	printf("== ZERO ==\n");
	while (i <= size)
	{
		ft_printf("|%04.7i| == ", arr[i]);
		   printf("|%04.7i|\n", arr[i]);
		i++;
	}
}

void	test_s(void)
{
	printf("\x1b[38;5;200m ___| |_ _ __(_)_ __   __ _ ___ \n");
	printf("/ __| __| '__| | '_ \\ / _` / __|\n");
	printf("\\__ \\ |_| |  | | | | | (_| \\__ \\\n");
	printf("|___/\\__|_|  |_|_| |_|\\__, |___/\n");
	printf("                      |___/\x1b[0m\n");
	ft_printf("|%-8s| == ", "abba");
	   printf("|%-8s|\n", "abba");
	ft_printf("|%-4s| == ", "abba");
	   printf("|%-4s|\n", "abba");
	ft_printf("|%-1s| == ", "abba");
	   printf("|%-1s|\n", "abba");
	ft_printf("|%-*s| == ", 0, "abba");
	   printf("|%-*s|\n", 0, "abba");
	ft_printf("|%8s| == ", "abba");
	   printf("|%8s|\n", "abba");
	ft_printf("|%4s| == ", "abba");
	   printf("|%4s|\n", "abba");
	ft_printf("|%1s| == ", "abba");
	   printf("|%1s|\n", "abba");
	ft_printf("|%*s| == ", 0, "abba");
	   printf("|%*s|\n", 0, "abba");
	ft_printf("|%.8s| == ", "abba");
	   printf("|%.8s|\n", "abba");
	ft_printf("|%.4s| == ", "abba");
	   printf("|%.4s|\n", "abba");
	ft_printf("|%.1s| == ", "abba");
	   printf("|%.1s|\n", "abba");
	ft_printf("|%.0s| == ", "abba");
	   printf("|%.0s|\n", "abba");
	ft_printf("|%8.4s| == ", "abcba");
	   printf("|%8.4s|\n", "abcba");
	ft_printf("|%4.6s| == ", "abcba");
	   printf("|%4.6s|\n", "abcba");
	ft_printf("|%1.4s| == ", "abcba");
	   printf("|%1.4s|\n", "abcba");
	ft_printf("|%*.4s| == ", 0, "abcba");
	   printf("|%*.4s|\n", 0, "abcba");
}

void	test_x(int *arr, int size)
{
	int	i;

	printf("\x1b[38;5;200m| |__   _____  __\n");
	printf("| '_ \\ / _ \\ \\/ /\n");
	printf("| | | |  __/>  < \n");
	printf("|_| |_|\\___/_/\\_\\\x1b[0m\n");
	i = 0;
	printf("== BASIC ==\n");
	while (i <= size)
	{
		ft_printf("|%x| == ", arr[i]);
		   printf("|%x|\n", arr[i]);
		i++;
	}
	i = 0;
	printf("== PRECISION ==\n");
	while (i <= size)
	{
		ft_printf("|%.5X| == ", arr[i]);
		   printf("|%.5X|\n", arr[i]);
		i++;
	}
	i = 0;
	printf("== FIELD WIDTH ==\n");
	while (i <= size)
	{
		ft_printf("|%5x| == ", arr[i]);
		   printf("|%5x|\n", arr[i]);
		i++;
	}
	i = 0;
	printf("== P > W ==\n");
	while (i <= size)
	{
		ft_printf("|%4.7X| == ", arr[i]);
		   printf("|%4.7X|\n", arr[i]);
		i++;
	}
	i = 0;
	printf("== P < W ==\n");
	while (i <= size)
	{
		ft_printf("|%7.4x| == ", arr[i]);
		   printf("|%7.4x|\n", arr[i]);
		i++;
	}
	i = 0;
	printf("== P = W ==\n");
	while (i <= size)
	{
		ft_printf("|%4.4X| == ", arr[i]);
		   printf("|%4.4X|\n", arr[i]);
		i++;
	}
	i = 0;
	printf("== 0P ==\n");
	while (i <= size)
	{
		ft_printf("|%.0x| == ", arr[i]);
		   printf("|%.0x|\n", arr[i]);
		i++;
	}
	i = 0;
	printf("== LEFT ==\n");
	while (i <= size)
	{
		ft_printf("|%-X| == ", arr[i]);
		   printf("|%-X|\n", arr[i]);
		i++;
	}
	i = 0;
	printf("== ZERO ==\n");
	while (i <= size)
	{
		ft_printf("|%04.7x| == ", arr[i]);
		   printf("|%04.7x|\n", arr[i]);
		i++;
	}
}

void	test_u(int *arr, int size)
{
	int	i;

	printf("\x1b[38;5;200m _   _ _ __  ___(_) __ _ _ __   ___  __| |\n");
	printf("| | | | '_ \\/ __| |/ _` | '_ \\ / _ \\/ _` |\n");
	printf("| |_| | | | \\__ \\ | (_| | | | |  __/ (_| |\n");
	printf(" \\__,_|_| |_|___/_|\\__, |_| |_|\\___|\\__,_|\n");
	printf("                   |___/                  \x1b[0m\n");
	i = 0;
	printf("== BASIC ==\n");
	while (i <= size)
	{
		ft_printf("|%u| == ", arr[i]);
		   printf("|%u|\n", arr[i]);
		i++;
	}
	i = 0;
	printf("== PRECISION ==\n");
	while (i <= size)
	{
		ft_printf("|%.5u| == ", arr[i]);
		   printf("|%.5u|\n", arr[i]);
		i++;
	}
	i = 0;
	printf("== FIELD WIDTH ==\n");
	while (i <= size)
	{
		ft_printf("|%5u| == ", arr[i]);
		   printf("|%5u|\n", arr[i]);
		i++;
	}
	i = 0;
	printf("== P > W ==\n");
	while (i <= size)
	{
		ft_printf("|%4.7u| == ", arr[i]);
		   printf("|%4.7u|\n", arr[i]);
		i++;
	}
	i = 0;
	printf("== P < W ==\n");
	while (i <= size)
	{
		ft_printf("|%7.4u| == ", arr[i]);
		   printf("|%7.4u|\n", arr[i]);
		i++;
	}
	i = 0;
	printf("== P = W ==\n");
	while (i <= size)
	{
		ft_printf("|%4.4u| == ", arr[i]);
		   printf("|%4.4u|\n", arr[i]);
		i++;
	}
	i = 0;
	printf("== 0P ==\n");
	while (i <= size)
	{
		ft_printf("|%.0u| == ", arr[i]);
		   printf("|%.0u|\n", arr[i]);
		i++;
	}
	i = 0;
	printf("== LEFT ==\n");
	while (i <= size)
	{
		ft_printf("|%*u| == ", -4, arr[i]);
		   printf("|%*u|\n", -4, arr[i]);
		i++;
	}
	i = 0;
	printf("== ZERO ==\n");
	while (i <= size)
	{
		ft_printf("|%04.7u| == ", arr[i]);
		   printf("|%04.7u|\n", arr[i]);
		i++;
	}
}

int	main(void)
{
	// int	amount;
	int	arr[9] = {1, -3, 2147483647, -2147483648, 69, -21, 1337, -1, 0};
	test_i(&arr[0], 8);
	test_s();
	test_x(&arr[0], 8);
	test_u(&arr[0], 8);
	// ft_printf("a%.0xc", 0);
	// printf("\nb%8.id", 0);

	// amount = ft_printf("%d", -50);
	//    printf("\n");
	//    printf(".%%syes %03.5dc a %-8.3d b %8d c %08d d %d", -130, -12, -11, 10, 10);
	//    printf("\n");
	// ft_printf(".%%syes %03.5dc a %-8.3d b %8d c %08d d %d", -130, -12, -11, 10, 10);
	// printf("\n%d\n", amount);
	// printf("%#05X", 11);
}
