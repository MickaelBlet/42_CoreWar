/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 16:57:36 by mblet             #+#    #+#             */
/*   Updated: 2016/11/10 16:50:31 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include "libft.h"

# include <stdarg.h>
# include <unistd.h>
# include <wchar.h>

# define VA_ARG(va_list, type)	((type)va_arg(va_list, type))

# define LIST_COLOR1	"{black};{red};{green};{yellow};{blue};{magenta}"
# define LIST_COLOR2	"{cyan};{light gray}"
# define LIST_COLOR3	"{dark gray};{light red};{light green};{light yellow}"
# define LIST_COLOR4	"{light blue};{light magenta};{light cyan};{white}"

typedef union				u_number
{
	unsigned long long int	longlong;
	unsigned long int		word;
	double					longdouble;
}							t_number;

typedef struct				s_printf_flag
{
	t_bool					is_negative;
	t_number				number;
	int						base;
	t_bool					alt;
	t_bool					space;
	t_bool					left;
	t_bool					showsign;
	t_bool					group;
	t_bool					is_long_double;
	t_bool					is_short;
	t_bool					is_long;
	t_bool					is_char;
	int						width;
	int						prec;
	char					pad;
	char					spec;
}							t_printf_flag;

typedef struct				s_printf
{
	char					*buffer;
	unsigned int			buffer_size;
	unsigned int			len;
	va_list					args;
	t_printf_flag			flags;
	char					*work_buffer;
	t_bool					search_color;
}							t_printf;

typedef struct				s_replace_color
{
	t_printf				*t;
	char					**tmp;
	int						*len;
	int						*i;
	int						*save;
}							t_replace_color;

typedef void				(*t_ptr_func)(t_printf *);

/*
** PRINTF
*/
int							ft_asprintf(char **ret, const char *format, ...);
int							ft_sprintf(char *ret, const char *format, ...);
int							ft_dprintf(int fd, const char *format, ...);
int							ft_printf(const char *format, ...);

/*
** FORMAT
*/
void						printf_format(t_printf *t, char *s);

/*
** ADD
*/
void						printf_add_char(t_printf *t, unsigned char c);
void						printf_add_wchar(t_printf *t, wchar_t c);
void						printf_add_string(t_printf *t, char *s,
		unsigned int len);
void						printf_fill_character(t_printf *t, char c);

/*
** CONVERSION
*/
void						printf_conversion_big_b(t_printf *t);
void						printf_conversion_b(t_printf *t);
void						printf_conversion_big_c(t_printf *t);
void						printf_conversion_c(t_printf *t);
void						printf_conversion_big_d(t_printf *t);
void						printf_conversion_big_f(t_printf *t);
void						printf_conversion_f(t_printf *t);
void						printf_conversion_i(t_printf *t);
void						printf_conversion_big_o(t_printf *t);
void						printf_conversion_o(t_printf *t);
void						printf_conversion_big_p(t_printf *t);
void						printf_conversion_p(t_printf *t);
void						printf_conversion_big_s(t_printf *t);
void						printf_conversion_s(t_printf *t);
void						printf_conversion_big_u(t_printf *t);
void						printf_conversion_u(t_printf *t);
void						printf_conversion_big_x(t_printf *t);
void						printf_conversion_x(t_printf *t);
t_bool						printf_function_conversion(t_printf *t, int index);

/*
** FLAGS
*/
t_bool						printf_flags(t_printf *t, char **s);
t_bool						printf_modifiers(t_printf *t, char **s);

/*
** LABELS
*/
void						printf_string(t_printf *t, char *s);
void						printf_char(t_printf *t, char c);
void						printf_wchar(t_printf *t, wchar_t c);
void						printf_number(t_printf *t);
void						printf_number_left(t_printf *t, unsigned int len);
void						printf_number_type(t_printf *t);
char						*printf_wstr_to_str(t_printf *t, wchar_t *s);

/*
** INI
*/
void						printf_ini(t_printf *t);
void						printf_ini_flags(t_printf *t);

/*
** COLOR
*/
void						printf_replace_color(t_printf *t, char *s, int len);
void						printf_color_basic(t_replace_color co);
void						printf_color_fg_bg(t_replace_color co);
void						printf_color_format(t_replace_color co);
char						*printf_concat(char *s1, int *len1,
		char *s2, int len2);
char						*printf_concat2(char *s1, int len1,
		char *s2, int len2);

#endif
