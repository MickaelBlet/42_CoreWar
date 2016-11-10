/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 04:48:27 by mblet             #+#    #+#             */
/*   Updated: 2016/11/10 17:59:11 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void		s_alt(t_printf *t)
{
	if (t->flags.alt != true)
		return ;
	if (t->flags.base == 16)
	{
		printf_add_char(t, '0');
		printf_add_char(t, t->flags.spec);
	}
	else if (t->flags.base == 8 && t->flags.number.word != 0)
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
		printf_add_char(t, '-');
	else if (t->flags.showsign)
		printf_add_char(t, '+');
	else if (t->flags.space)
		printf_add_char(t, ' ');
}

static void		s_if_flags(t_printf *t, unsigned int len)
{
	if (t->flags.base == 10)
	{
		if (t->flags.is_negative && t->flags.base == 10)
			t->flags.width -= 1;
		else if (t->flags.showsign && t->flags.base == 10)
			t->flags.width -= 1;
		else if (t->flags.space && t->flags.base == 10)
			t->flags.width -= 1;
	}
	else if (t->flags.alt)
	{
		if (t->flags.base == 16)
			t->flags.width -= 2;
		else if (t->flags.base == 8 && t->flags.prec <= (int)len)
			t->flags.width -= 1;
	}
}

static void		s_not_left(t_printf *t, unsigned int len)
{
	t->flags.width -= len + t->flags.prec;
	s_if_flags(t, len);
	if (t->flags.pad == ' ')
	{
		printf_fill_character(t, ' ');
		t->flags.width = 0;
	}
	s_flags(t);
	s_alt(t);
	t->flags.width += t->flags.prec;
	printf_fill_character(t, '0');
	printf_add_string(t, t->work_buffer, len);
}

void			printf_number(t_printf *t)
{
	unsigned int	len;

	if (t->flags.prec < 0 && t->flags.spec != 'f' && t->flags.spec != 'F')
		t->flags.prec = 1;
	else if (t->flags.spec != 'f' && t->flags.spec != 'F')
		t->flags.pad = ' ';
	if (t->flags.prec == 0 && t->flags.number.word == 0)
	{
		if ((t->flags.base == 8 && t->flags.alt)
			|| t->flags.spec == 'f' || t->flags.spec == 'F'
			|| t->flags.spec == 'b')
			printf_number_type(t);
	}
	else
		printf_number_type(t);
	len = ft_strlen(t->work_buffer);
	if ((t->flags.spec == 'f' || t->flags.spec == 'F') && t->flags.alt
		&& t->flags.prec == 0)
		t->work_buffer = printf_concat2(t->work_buffer, len, ".", 1);
	t->flags.prec = ft_max(0, t->flags.prec - len);
	if (t->flags.left)
		printf_number_left(t, len);
	else
		s_not_left(t, len);
}
