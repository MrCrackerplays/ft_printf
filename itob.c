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
	while (i < count)
	{
		converted[count - 1 - i] = base[n % base_size];
		n /= base_size;
		i++;
	}
	return (converted);
}

char	*ft_uitob(unsigned int n, const char *base)
{
	char	*converted;
	size_t	base_size;
	size_t	count;
	size_t	i;

	base_size = ft_strlen(base);
	if (base == NULL || base_size < 2)
		return (NULL);
	count = 0;
	i = n;
	while (i > 0)
	{
		i /= base_size;
		count++;
	}
	converted = insert_base(count, n, base_size, base);
	return (converted);
}
