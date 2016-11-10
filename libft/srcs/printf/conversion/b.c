/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 05:32:08 by mblet             #+#    #+#             */
/*   Updated: 2016/11/10 15:13:40 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	printf_conversion_big_b(t_printf *t)
{
	t->flags.base = 2;
	t->flags.spec = 'b';
	t->flags.is_negative = 0;
	t->flags.showsign = 0;
	t->flags.space = 0;
	t->flags.number.longlong = VA_ARG(t->args, unsigned long int);
	if (t->flags.number.longlong == 0)
		t->flags.alt = false;
	printf_number(t);
}

void	printf_conversion_b(t_printf *t)
{
	t->flags.base = 2;
	t->flags.spec = 'b';
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
