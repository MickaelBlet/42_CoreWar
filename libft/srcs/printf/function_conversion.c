/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_conversion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 12:10:46 by mblet             #+#    #+#             */
/*   Updated: 2016/11/10 16:50:46 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void			s_ini_functions(t_ptr_func *f)
{
	f['s'] = &printf_conversion_s;
	f['S'] = &printf_conversion_big_s;
	f['p'] = &printf_conversion_p;
	f['d'] = &printf_conversion_i;
	f['D'] = &printf_conversion_big_d;
	f['i'] = &printf_conversion_i;
	f['o'] = &printf_conversion_o;
	f['O'] = &printf_conversion_big_o;
	f['u'] = &printf_conversion_u;
	f['U'] = &printf_conversion_big_u;
	f['x'] = &printf_conversion_x;
	f['X'] = &printf_conversion_big_x;
	f['c'] = &printf_conversion_c;
	f['C'] = &printf_conversion_big_c;
	f['b'] = &printf_conversion_b;
	f['B'] = &printf_conversion_big_b;
	f['f'] = &printf_conversion_f;
	f['F'] = &printf_conversion_big_f;
}

static t_ptr_func	*s_singleton(void)
{
	static t_ptr_func	f[0xFF] = {0};
	static int			ini = 0;

	if (ini != 0)
		return (f);
	s_ini_functions(f);
	ini = 1;
	return (f);
}

t_bool				printf_function_conversion(t_printf *t, int index)
{
	if (index < 0 || index > 0xFF || s_singleton()[index] == NULL)
		return (false);
	s_singleton()[index](t);
	return (true);
}
