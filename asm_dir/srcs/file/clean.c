/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/24 23:36:42 by mblet             #+#    #+#             */
/*   Updated: 2016/10/24 23:49:48 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void		s_delete_label(t_label *label)
{
	ft_strdel(&label->name);
	free(label);
}

static void		s_delete_line(t_line *line)
{
	ft_strdel(&line->data);
	free(line);
}

void			file_clean(void)
{
	ft_lstd_clear(&sgt_asm()->file.lines, &s_delete_line);
	ft_lstd_clear(&sgt_asm()->file.labels, &s_delete_label);
}
