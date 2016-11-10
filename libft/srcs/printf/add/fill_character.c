/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_character.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/21 22:59:37 by mblet             #+#    #+#             */
/*   Updated: 2016/11/10 19:06:11 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

#include <stdlib.h>

static void		s_new_buffer(t_printf *t, long c)
{
	char	*tmp;

	t->buffer_size = t->len + sizeof(long) + BUFF_SIZE + 1;
	if ((tmp = (char *)malloc((t->buffer_size) * sizeof(char))) == NULL)
		return ;
	if (t->buffer)
	{
		ft_memcpy(tmp, t->buffer, t->len);
		*((long *)(tmp + t->len)) = c;
		t->len += sizeof(long);
	}
	else
	{
		*((long *)(tmp)) = c;
		t->len += sizeof(long);
	}
	ft_strdel(&t->buffer);
	t->buffer = (char *)tmp;
}

static void		s_printf_fill_speed(t_printf *t, long c)
{
	if ((t->len + sizeof(long)) > t->buffer_size)
		return (s_new_buffer(t, c));
	if (t->buffer)
	{
		*((long *)(t->buffer + t->len)) = c;
		t->len += sizeof(long);
	}
	else
	{
		s_new_buffer(t, c);
	}
}

void			printf_fill_character(t_printf *t, char c)
{
	if (t->flags.width >= (int)sizeof(long))
	{
		if (c == ' ')
		{
			while (t->flags.width >= (int)sizeof(long))
			{
				s_printf_fill_speed(t, 0x2020202020202020);
				t->flags.width -= sizeof(long);
			}
		}
		else
		{
			while (t->flags.width >= (int)sizeof(long))
			{
				s_printf_fill_speed(t, 0x3030303030303030);
				t->flags.width -= sizeof(long);
			}
		}
	}
	while (t->flags.width > 0)
	{
		printf_add_char(t, c);
		--t->flags.width;
	}
}
