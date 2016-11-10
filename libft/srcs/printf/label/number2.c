/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 05:05:40 by mblet             #+#    #+#             */
/*   Updated: 2016/11/10 16:23:05 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

#include <stdlib.h>

static void		s_ubasetoa_strcal(char **s, unsigned long int n,
		char *base, size_t len)
{
	if (n < len)
	{
		(**s) = base[n];
		++(*s);
	}
	else
	{
		s_ubasetoa_strcal(s, n / len, base, len);
		(**s) = base[n % len];
		++(*s);
	}
}

static char		*s_ubasetoa(unsigned long int n, char *base, int base_nb)
{
	char	*tmp;
	char	*str;

	if ((str = (char *)malloc(128 * sizeof(char))) == NULL)
		return (NULL);
	tmp = str;
	s_ubasetoa_strcal(&tmp, n, base, base_nb);
	str[tmp - str] = '\0';
	return (str);
}

static char		s_toupper(char c)
{
	if (('a' <= c) && (c <= 'z'))
		c = c - 32;
	return (c);
}

static void		s_float_check(t_printf *t)
{
	char	*str;

	if (t->flags.spec == 'f')
	{
		t->work_buffer = ft_ftoa(
				t->flags.number.longdouble,
				t->flags.prec);
		if (t->flags.number.longdouble
				!= t->flags.number.longdouble)
			t->flags.prec = -1;
	}
	else if (t->flags.spec == 'F')
	{
		t->work_buffer = ft_ftoa(
				t->flags.number.longdouble,
				t->flags.prec);
		if (t->flags.number.longdouble
				!= t->flags.number.longdouble)
			t->flags.prec = -1;
		str = ft_strmap(t->work_buffer, &s_toupper);
		ft_strdel(&t->work_buffer);
		t->work_buffer = str;
	}
}

void			printf_number_type(t_printf *t)
{
	if (t->flags.spec == 'f' || t->flags.spec == 'F')
		s_float_check(t);
	else if (t->flags.spec == 'b')
		t->work_buffer = s_ubasetoa(
				t->flags.number.longlong, "01", 2);
	else if (t->flags.spec == 'x')
		t->work_buffer = s_ubasetoa(
				t->flags.number.longlong, "0123456789abcdef", 16);
	else if (t->flags.spec == 'X')
		t->work_buffer = s_ubasetoa(
				t->flags.number.longlong, "0123456789ABCDEF", 16);
	else if (t->flags.base == 8)
		t->work_buffer = s_ubasetoa(
				t->flags.number.longlong, "01234567", 8);
	else
		t->work_buffer = s_ubasetoa(
				t->flags.number.longlong, "0123456789", 10);
}
