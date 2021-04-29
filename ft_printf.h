#ifndef FT_PRINTF_H
# define FT_PRINTF_H
/* Includes */
# include "stdarg.h"

/* Typedef Structs */
typedef struct s_conversion
{
	char	*str;
	int		flags;
	int		field_width;
	int		precision;
	char	specifier;
}	t_conversion;
/* Function Definitions */
int	ft_printf(const char *s, ...);
int	get_flags(const char *str, int *position);
int	get_field_width(const char *str, int *position, va_list *args);
int	get_precision(const char *str, int *position, va_list *args);
/* Global Variables */
const static char	*g_flags = "-0";
const static char	*g_conversions = "diuxXcsp%";
#endif
