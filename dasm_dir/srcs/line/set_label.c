/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_label.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/28 23:22:52 by mblet             #+#    #+#             */
/*   Updated: 2016/11/16 15:07:18 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dasm.h"

static t_bool	s_set_to_index(int index)
{
	t_listd		*list;
	t_line		*line;

	list = sgt_dasm()->lines;
	while (list)
	{
		line = list->data;
		if (line->index_cor == index)
		{
			line->has_label = true;
			return (true);
		}
		list = list->next;
	}
	return (false);
}

void			line_set_label(void)
{
	t_listd		*list;
	t_line		*line;
	int			i;

	list = sgt_dasm()->lines;
	while (list)
	{
		line = list->data;
		i = 0;
		while (i < line->op.nb_args)
		{
			if ((line->arg[i].type == T_DIR || line->arg[i].type == T_IND)
				&& line->arg[i].value != 0 && line->op.op_code != 1
				&& s_set_to_index(line->index_cor + line->arg[i].value))
			{
				line->arg[i].label = true;
				line->arg[i].id_label = line->index_cor + line->arg[i].value;
			}
			else
				line->arg[i].label = false;
			++i;
		}
		list = list->next;
	}
}
