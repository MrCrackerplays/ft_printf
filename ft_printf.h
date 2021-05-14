#ifndef FT_PRINTF_H
# define FT_PRINTF_H
/* Includes */
# include "stdarg.h"

/* Typedef Structs */
typedef struct s_conv
{
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
int		is_flag_set(int flag, char c);
int		get_specifier_index(char c);
char	*create_width_print(int width, char fill);
char	*ft_uitob(unsigned int n, char *base);
int		get_count(t_conv *data, int input, int base_size);
/* Specifier Parsers */
char	*parse_specifier_c(va_list *arg, t_conv *data);
char	*parse_specifier_d(va_list *arg, t_conv *data);
char	*parse_specifier_i(va_list *arg, t_conv *data);
char	*parse_specifier_p(va_list *arg, t_conv *data);
char	*parse_specifier_s(va_list *arg, t_conv *data);
char	*parse_specifier_u(va_list *arg, t_conv *data);
char	*parse_specifier_x(va_list *arg, t_conv *data);
char	*parse_specifier_X(va_list *arg, t_conv *data);
char	*parse_specifier_percent(va_list *arg, t_conv *data);
/* Global Variables */
const static char	*g_flags = "-0";
const static char	*g_specifiers = "diuxXcsp%";
#endif
