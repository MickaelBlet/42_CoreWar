/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/25 01:53:52 by mblet             #+#    #+#             */
/*   Updated: 2016/10/07 15:03:55 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		s_get_val(int **val, t_op op, size_t index)
{
	int		type[4];
	int		i;

	++index;
	byte_code_to_type(&type, sgt_corewar()->ram[index % MEM_SIZE]->data);
	i = 0;
	while (i < op.nb_args)
	{
		if (op.type_args[i] & type[i])
		{
			DG("%i", type[i]);
			(*val)[i] = 
		}
		else
		{
			ERR("reg.");
		}
		++i;
	}
}

void			check_op(t_process *process)
{
	int		i;
	int		val[4];

	i = 0;
	while (i < 16)
	{
		if (sgt_corewar()->ram[process->pc]->data == op_tab(i).op_code)
		{
			if (op_tab(i).has_pcode)
				s_get_val(op_tab(i), process->pc);
			func_tab(i)(process);
			return ;
		}
		++i;
	}
}
