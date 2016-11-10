/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_char.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/19 22:37:30 by mblet             #+#    #+#             */
/*   Updated: 2016/11/10 18:57:47 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

#include <stdlib.h>

static void		s_new_buffer(t_printf *t, unsigned char c)
{
	char	*tmp;

	t->buffer_size = t->len + 1 + BUFF_SIZE + 1;
	if ((tmp = (char *)malloc((t->buffer_size) * sizeof(char))) == NULL)
		return ;
	if (t->buffer)
	{
		ft_memcpy(tmp, t->buffer, t->len);
		tmp[t->len] = c;
		++t->len;
	}
	else
	{
		tmp[0] = c;
		++t->len;
	}
	ft_strdel(&t->buffer);
	t->buffer = tmp;
}

void			printf_add_char(t_printf *t, unsigned char c)
{
	if ((t->len + 1) > t->buffer_size)
		return (s_new_buffer(t, c));
	if (t->buffer)
	{
		t->buffer[t->len] = c;
		++t->len;
	}
	else
	{
		s_new_buffer(t, c);
	}
}
