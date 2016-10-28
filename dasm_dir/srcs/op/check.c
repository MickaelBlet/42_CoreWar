/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/28 21:20:43 by mblet             #+#    #+#             */
/*   Updated: 2016/10/29 00:49:03 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dasm.h"

static void		s_func(t_op op, t_line *line)
{
	sgt_dasm()->index_cor += 1;
	line->arg[0].type = op.type_args[0];
	line->arg[0].value = get_value_from_type(sgt_dasm()->index_cor,
			op.type_args[0], op.has_idx);
	sgt_dasm()->index_cor += (op.has_idx) ? 2 : 4;
}

static void		s_pcode(t_op op, t_line *line)
{
	int		type[4];
	int		i;

	ft_bzero(type, sizeof(int) * 4);
	byte_code_to_type(&type,
			sgt_dasm()->data[(sgt_dasm()->index_cor + 1) % CHAMP_MAX_SIZE]);
	sgt_dasm()->index_cor += 2;
	i = 0;
	while (i < op.nb_args)
	{
		line->arg[i].type = type[i];
		line->arg[i].value = get_value_from_type(sgt_dasm()->index_cor,
				type[i], op.has_idx);
		sgt_dasm()->index_cor += (type[i] == T_REG) ? 1 : 0;
		sgt_dasm()->index_cor += (type[i] == T_IND) ? 2 : 0;
		sgt_dasm()->index_cor += (type[i] == T_DIR && op.has_idx) ? 2 : 0;
		sgt_dasm()->index_cor += (type[i] == T_DIR && !op.has_idx) ? 4 : 0;
		++i;
	}
}

void			op_check(void)
{
	t_op		op;
	t_listd		*list;
	t_line		*line;

	list = NULL;
	while (sgt_dasm()->index_cor < sgt_dasm()->file.header->prog_size)
	{
		op = op_tab(sgt_dasm()->data[sgt_dasm()->index_cor] - 1);
		if (op.op_code == 0)
			return ((void)ERROR("%s: %s", sgt_dasm()->file_name, "bad file"));
		if ((line = line_creat(sgt_dasm()->index_cor, op)) == NULL)
			return ((void)ERROR("malloc"));
		if (op.has_pcode)
			s_pcode(op, line);
		else
			s_func(op, line);
		ft_lstd_push_back(&list, line);
		if (list->next != NULL)
			list = list->next;
		else
			sgt_dasm()->lines = list;
	}
	line_set_label();
	line_print();
	file_write();
}
