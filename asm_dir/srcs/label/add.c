/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/25 14:46:15 by mblet             #+#    #+#             */
/*   Updated: 2016/10/25 21:26:34 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	label_add(t_arg arg)
{
	t_arg	*label;

	if (label_check_name(arg.data) == false)
	{
		error_print(arg, ERR_LAB_NAME);
		return (ft_strdel(&arg.data));
	}
	if (label_check_same(arg.data) == false)
	{
		error_print(arg, ERR_LAB_SAME);
		return (ft_strdel(&arg.data));
	}
	if ((label = (t_arg *)malloc(sizeof(t_arg))) == NULL)
	{
		ERROR("malloc.");
		return (ft_strdel(&arg.data));
	}
	label->line = arg.line;
	label->column = arg.column;
	label->index_cor = sgt_asm()->index_cor;
	label->type = T_LAB;
	label->data = arg.data;
	ft_lstd_push_front(&sgt_asm()->labels, label);
}
