/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/24 23:36:42 by mblet             #+#    #+#             */
/*   Updated: 2016/10/25 16:18:00 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void		s_delete_arg(t_arg *arg)
{
	ft_strdel(&arg->data);
	free(arg);
}

static void		s_delete_line(t_line *line)
{
	ft_strdel(&line->data);
	free(line);
}

void			file_clean(void)
{
	ft_lstd_clear(&sgt_asm()->lines, &s_delete_line);
	ft_lstd_clear(&sgt_asm()->labels, &s_delete_arg);
}
