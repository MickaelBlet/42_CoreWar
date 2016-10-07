/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 09:54:50 by mblet             #+#    #+#             */
/*   Updated: 2016/10/04 23:10:08 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		s_action(t_process *process, int type[4])
{
	t_byte	*b;
	int		val0;
	int		val1;
	int		val2;

	b = process->pc + 2;
		val0 = get_reg_value(b);
		b += 1;
	if (type[1] == T_REG)
	{
		val1 = get_reg_value(b);
		b += 1;
	}
	else
	{
		val1 = get_dir_value(b);
		b += 2;
	}
	if (type[2] == T_REG)
	{
		val2 = get_reg_value(b);
		b += 1;
	}
	else
	{
		val2 = get_dir_value(b);
		b += 2;
	}
	DG("%i %i %i", val1, val2, val1 + val2);
	set_4byte_value(process, process->pc + val1 + val2, process->reg[val0]);
}

void			op_sti(t_process *process)
{
	int		types[4];
	size_t	size;

	size = 1;
	byte_code_to_type(&types, (process->pc + 1)->data);
	if (types[0] != T_REG || types[1] == 0
		|| !(types[2] == T_DIR || types[2] == T_REG))
		process->carry = 1;
	else
	{
		if (types[0] == T_REG)
			size += 1;
		if (types[1] == T_REG)
			size += 1;
		else if (types[1] == T_DIR || types[1] == T_IND)
			size += 2;
		if (types[2] == T_REG)
			size += 1;
		else if (types[2] == T_DIR)
			size += 2;
		size += 1;
		s_action(process, types);
	}
	process->pc += size;
}
