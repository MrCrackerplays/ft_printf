#ifndef FT_PRINTF_H
# define FT_PRINTF_H
/* Includes */
# include "stdarg.h"

/* Typedef Structs */
typedef struct s_conv
{
	char	*str;
	int		flags;
	int		field_width;
	int		precision;
	int		length_mod;
	char	specifier;
}	t_conv;
/* Function Definitions */
int		ft_printf(const char *s, ...);
int		get_flags(const char *str, int *position);
int		get_field_width(const char *str, int *position, va_list *args);
int		get_precision(const char *str, int *position, va_list *args);
char	get_specifier(const char *str, int *position);
int		get_flag_value(char c);
int		get_specifier_index(char c);
/* Specifier Parsers */
char	*parse_specifier_c(t_conv *data);
char	*parse_specifier_d(t_conv *data);
char	*parse_specifier_i(t_conv *data);
char	*parse_specifier_p(t_conv *data);
char	*parse_specifier_s(t_conv *data);
char	*parse_specifier_u(t_conv *data);
char	*parse_specifier_x(t_conv *data);
char	*parse_specifier_X(t_conv *data);
char	*parse_specifier_percent(t_conv *data);
/* Global Variables */
const static char	*g_flags = "-0";
const static char	*g_specifiers = "diuxXcsp%";
#endif
