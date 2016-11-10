/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_left.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 05:21:32 by mblet             #+#    #+#             */
/*   Updated: 2016/11/10 17:56:24 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void		s_alt(t_printf *t)
{
	if (t->flags.alt == false)
		return ;
	if (t->flags.base == 16)
	{
		printf_add_char(t, L'0');
		printf_add_char(t, t->flags.spec);
		t->flags.width -= 2;
	}
	if (t->flags.base == 8 && t->flags.number.word != 0)
	{
		printf_add_char(t, '0');
		t->flags.width -= 1;
	}
}

static void		s_flags(t_printf *t)
{
	if (t->flags.base != 10)
		return ;
	if (t->flags.is_negative)
	{
		printf_add_char(t, '-');
		t->flags.width -= 1;
	}
	else if (t->flags.showsign)
	{
		printf_add_char(t, '+');
		t->flags.width -= 1;
	}
	else if (t->flags.space)
	{
		printf_add_char(t, ' ');
		t->flags.width -= 1;
	}
}

void			printf_number_left(t_printf *t, unsigned int len)
{
	int		temp;

	s_flags(t);
	s_alt(t);
	t->flags.width -= len + t->flags.prec;
	if (t->flags.prec > 0)
	{
		temp = t->flags.width;
		t->flags.width = t->flags.prec;
		if (t->flags.alt && t->flags.base == 8 && t->flags.number.word != 0)
		{
			t->flags.width -= 1;
			temp += 1;
		}
		printf_fill_character(t, '0');
		t->flags.width = temp;
	}
	printf_add_string(t, t->work_buffer, len);
	printf_fill_character(t, ' ');
}
