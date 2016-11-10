/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 08:24:04 by mblet             #+#    #+#             */
/*   Updated: 2016/11/10 15:17:42 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	printf_conversion_big_f(t_printf *t)
{
	t->flags.base = 10;
	t->flags.spec = 'F';
	t->flags.number.longdouble = VA_ARG(t->args, double);
	if (t->flags.number.longdouble < 0)
	{
		t->flags.number.longdouble =
			t->flags.number.longdouble * -1;
		t->flags.is_negative = true;
	}
	printf_number(t);
}

void	printf_conversion_f(t_printf *t)
{
	t->flags.base = 10;
	t->flags.spec = 'f';
	if (t->flags.is_long)
		return ((void)printf_conversion_big_f(t));
	else
		t->flags.number.longdouble = VA_ARG(t->args, double);
	if (t->flags.number.longdouble < 0)
	{
		t->flags.number.longdouble =
			t->flags.number.longdouble * -1;
		t->flags.is_negative = true;
	}
	printf_number(t);
}
