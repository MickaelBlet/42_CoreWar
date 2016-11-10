/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 10:04:49 by mblet             #+#    #+#             */
/*   Updated: 2016/11/10 16:19:58 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void		s_replace(t_replace_color co)
{
	printf_color_fg_bg(co);
	printf_color_basic(co);
	printf_color_format(co);
}

void			printf_replace_color(t_printf *t, char *s, int len)
{
	int		i;
	int		tmp_len;
	int		save;
	char	*tmp;

	i = 0;
	tmp_len = 0;
	save = 0;
	tmp = NULL;
	while (i < len)
	{
		s_replace((t_replace_color){t, &tmp, &tmp_len, &i, &save});
		++i;
	}
	tmp = printf_concat(tmp, &tmp_len, s + save, i - save);
	ft_strdel(&t->buffer);
	t->buffer = tmp;
	t->len = tmp_len;
}
