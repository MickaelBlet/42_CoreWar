/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 17:26:50 by mblet             #+#    #+#             */
/*   Updated: 2016/11/10 15:18:45 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	printf_conversion_big_u(t_printf *t)
{
	t->flags.base = 10;
	t->flags.is_negative = 0;
	t->flags.showsign = 0;
	t->flags.space = 0;
	t->flags.number.longlong = VA_ARG(t->args, unsigned long int);
	printf_number(t);
}

void	printf_conversion_u(t_printf *t)
{
	t->flags.base = 10;
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
	printf_number(t);
}
