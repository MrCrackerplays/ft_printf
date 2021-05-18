#include "stdio.h"
#include "ft_printf.h"
#include "libft/libft.h"

void	test_i(int *arr, int size)
{
	int	i;
	int	a;
	int	b;

	printf("\x1b[38;5;200m(_)_ __ | |_ ___  __ _  ___ _ __ ___ \n");
	printf("| | '_ \\| __/ _ \\/ _` |/ _ \\ '__/ __|\n");
	printf("| | | | | ||  __/ (_| |  __/ |  \\__ \\\n");
	printf("|_|_| |_|\\__\\___|\\__, |\\___|_|  |___/\n");
	printf("                 |___/               \x1b[0m\n");
	i = 0;
	printf("== BASIC ==\n");
	while (i < size)
	{
		a = ft_printf("|%d| == ", arr[i]);
		b =    printf("|%d|\n", arr[i]);
		if (a - 3 != b)
			printf("%i != %i", a - 3, b);
		i++;
	}
	i = 0;
	printf("== PRECISION ==\n");
	while (i < size)
	{
		a = ft_printf("|%.5i| == ", arr[i]);
		b =    printf("|%.5i|\n", arr[i]);
		if (a - 3 != b)
			printf("%i != %i", a - 3, b);
		i++;
	}
	i = 0;
	printf("== FIELD WIDTH ==\n");
	while (i < size)
	{
		a = ft_printf("|%5i| == ", arr[i]);
		b =    printf("|%5i|\n", arr[i]);
		if (a - 3 != b)
			printf("%i != %i", a - 3, b);
		i++;
	}
	i = 0;
	printf("== P > W ==\n");
	while (i < size)
	{
		a = ft_printf("|%4.7i| == ", arr[i]);
		b =    printf("|%4.7i|\n", arr[i]);
		if (a - 3 != b)
			printf("%i != %i", a - 3, b);
		i++;
	}
	i = 0;
	printf("== P < W ==\n");
	while (i < size)
	{
		a = ft_printf("|%7.4i| == ", arr[i]);
		b =    printf("|%7.4i|\n", arr[i]);
		if (a - 3 != b)
			printf("%i != %i", a - 3, b);
		i++;
	}
	i = 0;
	printf("== P = W ==\n");
	while (i < size)
	{
		a = ft_printf("|%4.4i| == ", arr[i]);
		b =    printf("|%4.4i|\n", arr[i]);
		if (a - 3 != b)
			printf("%i != %i", a - 3, b);
		i++;
	}
	i = 0;
	printf("== 0P ==\n");
	while (i < size)
	{
		a = ft_printf("|%.0i| == ", arr[i]);
		b =    printf("|%.0i|\n", arr[i]);
		if (a - 3 != b)
			printf("%i != %i", a - 3, b);
		i++;
	}
	i = 0;
	printf("== LEFT ==\n");
	while (i < size)
	{
		a = ft_printf("|%*i| == ", -4, arr[i]);
		b =    printf("|%*i|\n", -4, arr[i]);
		if (a - 3 != b)
			printf("%i != %i", a - 3, b);
		i++;
	}
	i = 0;
	printf("== ZERO ==\n");
	while (i < size)
	{
		a = ft_printf("|%04.7i| == ", arr[i]);
		b =    printf("|%04.7i|\n", arr[i]);
		if (a - 3 != b)
			printf("%i != %i", a - 3, b);
		i++;
	}
}

void	test_s(void)
{
	int	a;
	int	b;
	printf("\x1b[38;5;200m ___| |_ _ __(_)_ __   __ _ ___ \n");
	printf("/ __| __| '__| | '_ \\ / _` / __|\n");
	printf("\\__ \\ |_| |  | | | | | (_| \\__ \\\n");
	printf("|___/\\__|_|  |_|_| |_|\\__, |___/\n");
	printf("                      |___/\x1b[0m\n");
	a = ft_printf("|%-8s| == ", "abba");
	b =    printf("|%-8s|\n", "abba");
	if (a - 3 != b)
		printf("%i != %i", a - 3, b);
	a = ft_printf("|%-4s| == ", "abba");
	b =    printf("|%-4s|\n", "abba");
	if (a - 3 != b)
		printf("%i != %i", a - 3, b);
	a = ft_printf("|%-1s| == ", "abba");
	b =    printf("|%-1s|\n", "abba");
	if (a - 3 != b)
		printf("%i != %i", a - 3, b);
	a = ft_printf("|%-*s| == ", 0, "abba");
	b =    printf("|%-*s|\n", 0, "abba");
	if (a - 3 != b)
		printf("%i != %i", a - 3, b);
	a = ft_printf("|%8s| == ", "abba");
	b =    printf("|%8s|\n", "abba");
	if (a - 3 != b)
		printf("%i != %i", a - 3, b);
	a = ft_printf("|%4s| == ", "abba");
	b =    printf("|%4s|\n", "abba");
	if (a - 3 != b)
		printf("%i != %i", a - 3, b);
	a = ft_printf("|%1s| == ", "abba");
	b =    printf("|%1s|\n", "abba");
	if (a - 3 != b)
		printf("%i != %i", a - 3, b);
	a = ft_printf("|%*s| == ", 0, "abba");
	b =    printf("|%*s|\n", 0, "abba");
	if (a - 3 != b)
		printf("%i != %i", a - 3, b);
	a = ft_printf("|%.8s| == ", "abba");
	b =    printf("|%.8s|\n", "abba");
	if (a - 3 != b)
		printf("%i != %i", a - 3, b);
	a = ft_printf("|%.4s| == ", "abba");
	b =    printf("|%.4s|\n", "abba");
	if (a - 3 != b)
		printf("%i != %i", a - 3, b);
	a = ft_printf("|%.1s| == ", "abba");
	b =    printf("|%.1s|\n", "abba");
	if (a - 3 != b)
		printf("%i != %i", a - 3, b);
	a = ft_printf("|%.0s| == ", "abba");
	b =    printf("|%.0s|\n", "abba");
	if (a - 3 != b)
		printf("%i != %i", a - 3, b);
	a = ft_printf("|%8.4s| == ", "abcba");
	b =    printf("|%8.4s|\n", "abcba");
	if (a - 3 != b)
		printf("%i != %i", a - 3, b);
	a = ft_printf("|%4.6s| == ", "abcba");
	b =    printf("|%4.6s|\n", "abcba");
	if (a - 3 != b)
		printf("%i != %i", a - 3, b);
	a = ft_printf("|%1.4s| == ", "abcba");
	b =    printf("|%1.4s|\n", "abcba");
	if (a - 3 != b)
		printf("%i != %i", a - 3, b);
	a = ft_printf("|%*.4s| == ", 0, "abcba");
	b =    printf("|%*.4s|\n", 0, "abcba");
	if (a - 3 != b)
		printf("%i != %i", a - 3, b);
	a = ft_printf("|%s| == ", NULL);
	b =    printf("|%s|\n", NULL);
	if (a - 3 != b)
		printf("%i != %i", a - 3, b);
}

void	test_x(int *arr, int size)
{
	int	i;
	int	a;
	int	b;

	printf("\x1b[38;5;200m| |__   _____  __\n");
	printf("| '_ \\ / _ \\ \\/ /\n");
	printf("| | | |  __/>  < \n");
	printf("|_| |_|\\___/_/\\_\\\x1b[0m\n");
	i = 0;
	printf("== BASIC ==\n");
	while (i < size)
	{
		a = ft_printf("|%x| == ", arr[i]);
		b =    printf("|%x|\n", arr[i]);
		if (a - 3 != b)
			printf("%i != %i", a - 3, b);
		i++;
	}
	i = 0;
	printf("== PRECISION ==\n");
	while (i < size)
	{
		a = ft_printf("|%.5X| == ", arr[i]);
		b =    printf("|%.5X|\n", arr[i]);
		if (a - 3 != b)
			printf("%i != %i", a - 3, b);
		i++;
	}
	i = 0;
	printf("== FIELD WIDTH ==\n");
	while (i < size)
	{
		a = ft_printf("|%5x| == ", arr[i]);
		b =    printf("|%5x|\n", arr[i]);
		if (a - 3 != b)
			printf("%i != %i", a - 3, b);
		i++;
	}
	i = 0;
	printf("== P > W ==\n");
	while (i < size)
	{
		a = ft_printf("|%4.7X| == ", arr[i]);
		b =    printf("|%4.7X|\n", arr[i]);
		if (a - 3 != b)
			printf("%i != %i", a - 3, b);
		i++;
	}
	i = 0;
	printf("== P < W ==\n");
	while (i < size)
	{
		a = ft_printf("|%7.4x| == ", arr[i]);
		b =    printf("|%7.4x|\n", arr[i]);
		if (a - 3 != b)
			printf("%i != %i", a - 3, b);
		i++;
	}
	i = 0;
	printf("== P = W ==\n");
	while (i < size)
	{
		a = ft_printf("|%4.4X| == ", arr[i]);
		b =    printf("|%4.4X|\n", arr[i]);
		if (a - 3 != b)
			printf("%i != %i", a - 3, b);
		i++;
	}
	i = 0;
	printf("== 0P ==\n");
	while (i < size)
	{
		a = ft_printf("|%.0x| == ", arr[i]);
		b =    printf("|%.0x|\n", arr[i]);
		if (a - 3 != b)
			printf("%i != %i", a - 3, b);
		i++;
	}
	i = 0;
	printf("== LEFT ==\n");
	while (i < size)
	{
		a = ft_printf("|%-X| == ", arr[i]);
		b =    printf("|%-X|\n", arr[i]);
		if (a - 3 != b)
			printf("%i != %i", a - 3, b);
		i++;
	}
	i = 0;
	printf("== ZERO ==\n");
	while (i < size)
	{
		a = ft_printf("|%04.7x| == ", arr[i]);
		b =    printf("|%04.7x|\n", arr[i]);
		if (a - 3 != b)
			printf("%i != %i", a - 3, b);
		i++;
	}
}

void	test_u(int *arr, int size)
{
	int	i;
	int	a;
	int	b;

	printf("\x1b[38;5;200m _   _ _ __  ___(_) __ _ _ __   ___  __| |\n");
	printf("| | | | '_ \\/ __| |/ _` | '_ \\ / _ \\/ _` |\n");
	printf("| |_| | | | \\__ \\ | (_| | | | |  __/ (_| |\n");
	printf(" \\__,_|_| |_|___/_|\\__, |_| |_|\\___|\\__,_|\n");
	printf("                   |___/                  \x1b[0m\n");
	i = 0;
	printf("== BASIC ==\n");
	while (i < size)
	{
		a = ft_printf("|%u| == ", arr[i]);
		b =    printf("|%u|\n", arr[i]);
		if (a - 3 != b)
			printf("%i != %i", a - 3, b);
		i++;
	}
	i = 0;
	printf("== PRECISION ==\n");
	while (i < size)
	{
		a = ft_printf("|%.5u| == ", arr[i]);
		b =    printf("|%.5u|\n", arr[i]);
		if (a - 3 != b)
			printf("%i != %i", a - 3, b);
		i++;
	}
	i = 0;
	printf("== FIELD WIDTH ==\n");
	while (i < size)
	{
		a = ft_printf("|%5u| == ", arr[i]);
		b =    printf("|%5u|\n", arr[i]);
		if (a - 3 != b)
			printf("%i != %i", a - 3, b);
		i++;
	}
	i = 0;
	printf("== P > W ==\n");
	while (i < size)
	{
		a = ft_printf("|%4.7u| == ", arr[i]);
		b =    printf("|%4.7u|\n", arr[i]);
		if (a - 3 != b)
			printf("%i != %i", a - 3, b);
		i++;
	}
	i = 0;
	printf("== P < W ==\n");
	while (i < size)
	{
		a = ft_printf("|%7.4u| == ", arr[i]);
		b =    printf("|%7.4u|\n", arr[i]);
		if (a - 3 != b)
			printf("%i != %i", a - 3, b);
		i++;
	}
	i = 0;
	printf("== P = W ==\n");
	while (i < size)
	{
		a = ft_printf("|%4.4u| == ", arr[i]);
		b =    printf("|%4.4u|\n", arr[i]);
		if (a - 3 != b)
			printf("%i != %i", a - 3, b);
		i++;
	}
	i = 0;
	printf("== 0P ==\n");
	while (i < size)
	{
		a = ft_printf("|%.0u| == ", arr[i]);
		b =    printf("|%.0u|\n", arr[i]);
		if (a - 3 != b)
			printf("%i != %i", a - 3, b);
		i++;
	}
	i = 0;
	printf("== LEFT ==\n");
	while (i < size)
	{
		a = ft_printf("|%*u| == ", -4, arr[i]);
		b =    printf("|%*u|\n", -4, arr[i]);
		if (a - 3 != b)
			printf("%i != %i", a - 3, b);
		i++;
	}
	i = 0;
	printf("== ZERO ==\n");
	while (i < size)
	{
		a = ft_printf("|%04.7u| == ", arr[i]);
		b =    printf("|%04.7u|\n", arr[i]);
		if (a - 3 != b)
			printf("%i != %i", a - 3, b);
		i++;
	}
}

void	test_p(int *arr, int size)
{
	int	i;
	int	a;
	int	b;

	printf("\x1b[38;5;200m _ __   ___ (_)_ __ | |_ ___ _ __ ___ \n");
	printf("| '_ \\ / _ \\| | '_ \\| __/ _ \\ '__/ __|\n");
	printf("| |_) | (_) | | | | | ||  __/ |  \\__ \\\n");
	printf("| .__/ \\___/|_|_| |_|\\__\\___|_|  |___/\n");
	printf("|_|\x1b[0m\n");
	i = 0;
	printf("== BASIC ==\n");
	while (i < size)
	{
		a = ft_printf("|%p| == ", (void*)(long)arr[i]);
		b =    printf("|%p|\n", (void*)(long)arr[i]);
		if (a - 3 != b)
			printf("%i != %i", a - 3, b);
		i++;
	}
	i = 0;
	printf("== FIELD WIDTH ==\n");
	while (i < size)
	{
		a = ft_printf("|%5p| == ", (void*)(long)arr[i]);
		b =    printf("|%5p|\n", (void*)(long)arr[i]);
		if (a - 3 != b)
			printf("%i != %i", a - 3, b);
		i++;
	}
	i = 0;
	printf("== LEFT ==\n");
	while (i < size)
	{
		a = ft_printf("|%*p| == ", -4, (void*)(long)arr[i]);
		b =    printf("|%*p|\n", -4, (void*)(long)arr[i]);
		if (a - 3 != b)
			printf("%i != %i", a - 3, b);
		i++;
	}
}

void	test_c(int *arr, int size)
{
	int	i;
	int	a;
	int	b;

	printf("\x1b[38;5;200m  ___| |__   __ _ _ __ \n");
	printf(" / __| '_ \\ / _` | '__|\n");
	printf("| (__| | | | (_| | |   \n");
	printf(" \\___|_| |_|\\__,_|_|\x1b[0m\n");
	i = 0;
	printf("== BASIC ==\n");
	while (i < size)
	{
		a = ft_printf("|%c| == ", arr[i]);
		b =    printf("|%c|\n", arr[i]);
		if (a - 3 != b)
			ft_printf("%i != %i", a - 3, b);
		i++;
	}
	i = 0;
	printf("== FIELD WIDTH ==\n");
	while (i < size)
	{
		a = ft_printf("|%5c| == ", arr[i]);
		b =    printf("|%5c|\n", arr[i]);
		if (a - 3 != b)
			ft_printf("%i != %i", a - 3, b);
		i++;
	}
	i = 0;
	printf("== LEFT ==\n");
	while (i < size)
	{
		a = ft_printf("|%*c| == ", -4, arr[i]);
		b =    printf("|%*c|\n", -4, arr[i]);
		if (a - 3 != b)
			ft_printf("%i != %i", a - 3, b);
		i++;
	}
}

void	test_percent(void)
{
	int	a;
	int	b;
	printf("\x1b[38;5;200m(_)/ /\n");
	printf("  / / \n");
	printf(" / /_ \n");
	printf("/_/(_)\x1b[0m\n");
	a = ft_printf("|%%| == ");
	b =    printf("|%%|\n");
	if (a - 3 != b)
		printf("%i != %i", a - 3, b);
}

void	test_o(int *arr, int size)
{
	int	i;
	int	a;
	int	b;

	printf("\x1b[38;5;200m  ___   ___| |_ __ _| |\n");
	printf(" / _ \\ / __| __/ _` | |\n");
	printf("| (_) | (__| || (_| | |\n");
	printf(" \\___/ \\___|\\__\\__,_|_|\x1b[0m\n");
	i = 0;
	printf("== BASIC ==\n");
	while (i < size)
	{
		a = ft_printf("|%o| == ", arr[i]);
		b =    printf("|%o|\n", arr[i]);
		if (a - 3 != b)
			printf("%i != %i", a - 3, b);
		i++;
	}
	i = 0;
	printf("== PRECISION ==\n");
	while (i < size)
	{
		a = ft_printf("|%.5o| == ", arr[i]);
		b =    printf("|%.5o|\n", arr[i]);
		if (a - 3 != b)
			printf("%i != %i", a - 3, b);
		i++;
	}
	i = 0;
	printf("== FIELD WIDTH ==\n");
	while (i < size)
	{
		a = ft_printf("|%5o| == ", arr[i]);
		b =    printf("|%5o|\n", arr[i]);
		if (a - 3 != b)
			printf("%i != %i", a - 3, b);
		i++;
	}
	i = 0;
	printf("== P > W ==\n");
	while (i < size)
	{
		a = ft_printf("|%4.7o| == ", arr[i]);
		b =    printf("|%4.7o|\n", arr[i]);
		if (a - 3 != b)
			printf("%i != %i", a - 3, b);
		i++;
	}
	i = 0;
	printf("== P < W ==\n");
	while (i < size)
	{
		a = ft_printf("|%7.4o| == ", arr[i]);
		b =    printf("|%7.4o|\n", arr[i]);
		if (a - 3 != b)
			printf("%i != %i", a - 3, b);
		i++;
	}
	i = 0;
	printf("== P = W ==\n");
	while (i < size)
	{
		a = ft_printf("|%4.4o| == ", arr[i]);
		b =    printf("|%4.4o|\n", arr[i]);
		if (a - 3 != b)
			printf("%i != %i", a - 3, b);
		i++;
	}
	i = 0;
	printf("== 0P ==\n");
	while (i < size)
	{
		a = ft_printf("|%.0o| == ", arr[i]);
		b =    printf("|%.0o|\n", arr[i]);
		if (a - 3 != b)
			printf("%i != %i", a - 3, b);
		i++;
	}
	i = 0;
	printf("== LEFT ==\n");
	while (i < size)
	{
		a = ft_printf("|%-o| == ", arr[i]);
		b =    printf("|%-o|\n", arr[i]);
		if (a - 3 != b)
			printf("%i != %i", a - 3, b);
		i++;
	}
	i = 0;
	printf("== ZERO ==\n");
	while (i < size)
	{
		a = ft_printf("|%04.7o| == ", arr[i]);
		b =    printf("|%04.7o|\n", arr[i]);
		if (a - 3 != b)
			printf("%i != %i", a - 3, b);
		i++;
	}
}

int	main(void)
{
	int	arr[9] = {1, -3, 2147483647, -2147483648, 69, -21, 1337, -1, 0};
	// test_c(&arr[0], 9);
	// test_s();
	// test_p(&arr[0], 9);
	test_i(&arr[0], 9);
	// test_u(&arr[0], 9);
	// test_x(&arr[0], 9);
	// test_percent();
	// test_o(&arr[0], 9);
	// int a;
	// int b;
	// a = ft_printf("%9s\n", NULL);
	//    b = printf("%9s\n", NULL);
	// if (a != b)
	// 	printf("%i != %i", a, b);
}
