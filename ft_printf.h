#ifndef FT_PRINTF_H
# define FT_PRINTF_H
/* Includes */
# include "stdarg.h"

/* Typedef Structs */
/* Function Definitions */
int	ft_printf(const char *s, ...);
int	get_flags(const char *str, int *position);
/* Global Variables */
const static char	*g_flags = "-0";
const static char	*g_conversions = "diuxXcsp%";
#endif
