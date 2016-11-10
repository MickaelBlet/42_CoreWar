/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 15:24:36 by mblet             #+#    #+#             */
/*   Updated: 2016/11/10 15:18:48 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	printf_conversion_big_x(t_printf *t)
{
	t->flags.base = 16;
	t->flags.spec = 'X';
	t->flags.is_negative = 0;
	t->flags.showsign = 0;
	t->flags.space = 0;
	if (t->flags.is_long)
		t->flags.number.longlong = VA_ARG(t->args, unsigned long int);
	else if (t->flags.is_char)
		t->flags.number.longlong = (unsigned char)VA_ARG(t->args, int);
	else
		t->flags.number.longlong = VA_ARG(t->args, unsigned int);
	if (t->flags.number.longlong == 0)
		t->flags.alt = false;
	printf_number(t);
}

void	printf_conversion_x(t_printf *t)
{
	t->flags.base = 16;
	t->flags.spec = 'x';
	t->flags.is_negative = 0;
	t->flags.showsign = 0;
	t->flags.space = 0;
	if (t->flags.is_long)
		t->flags.number.longlong = VA_ARG(t->args, unsigned long int);
	else if (t->flags.is_char)
		t->flags.number.longlong = (unsigned char)VA_ARG(t->args, unsigned int);
	else if (t->flags.is_short)
		t->flags.number.longlong =
			(unsigned short int)VA_ARG(t->args, unsigned int);
	else
		t->flags.number.longlong = VA_ARG(t->args, unsigned int);
	if (t->flags.number.longlong == 0)
		t->flags.alt = false;
	printf_number(t);
}
