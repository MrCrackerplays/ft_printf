#include "ft_printf.h"
#include "libft/libft.h"
#include "stdlib.h"

char	*insert_base(size_t count, unsigned int n, size_t base_size, char *base)
{
	size_t	i;
	char	*converted;

	i = 0;
	converted = malloc(sizeof(char) * (count + 1));
	if (converted == NULL)
		return (NULL);
	converted[count] = '\0';
	while (i < count)
	{
		converted[count - 1 - i] = base[n % base_size];
		n /= base_size;
		i++;
	}
	return (converted);
}

char	*ft_uitob(unsigned int n, char *base)
{
	size_t	base_size;
	size_t	count;
	size_t	i;

	base_size = ft_strlen(base);
	if (base == NULL || base_size < 2)
		return (NULL);
	count = 1;
	i = n;
	while (i >= base_size)
	{
		i /= base_size;
		count++;
	}
	return (insert_base(count, n, base_size, base));
}