/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 09:38:33 by mblet             #+#    #+#             */
/*   Updated: 2016/10/04 23:06:48 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		s_action(t_process *process, int type[4])
{
	t_byte	*b;
	int		val0;
	int		val1;

	b = process->pc + 2;
	if (type[0] == T_IND)
	{
		val0 = get_ind_value(b);
		b += 4;
	}
	else
	{
		val0 = get_dir_value(b);
		b += 4;
	}
	val1 = get_reg_value(b);
	if (val1 >= REG_NUMBER)
		process->carry = 1;
	else
	{
		DG("%i %i", val1, val0);
		process->reg[val1] = val0;
	}
}

void			op_ld(t_process *process)
{
	int		types[4];
	int		size;

	size = 1;
	DG("%p", process->pc);
	byte_code_to_type(&types, (process->pc + 1)->data);
	if (!(types[0] == T_DIR || types[0] == T_IND) || types[1] != T_REG)
		process->carry = 1;
	else
	{
		if (types[0] == T_IND)
			size += 4;
		if (types[0] == T_DIR)
			size += 4;
		size += 1;
		size += 1;
		s_action(process, types);
	}
	DG("%i", size);
	DG("%p", process->pc);
	process->pc += size;
	DG("%p", process->pc);
}
