/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 12:04:49 by mblet             #+#    #+#             */
/*   Updated: 2016/10/16 01:11:26 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		s_if_reg(t_process *process, int type[4], int arg[4])
{
	(void)type;
	if (arg[0] > 0 && arg[0] <= REG_NUMBER
		&& arg[1] > 0 && arg[1] <= REG_NUMBER)
	{
		set_4byte_value(process, process->pc + \
				(process->reg[arg[1] - 1] % IDX_MOD),
				process->reg[arg[0] - 1]);
		process->carry = 1;
	}
	else
	{
		process->carry = 0;
	}
}

static void		s_if_not_reg(t_process *process, int type[4], int arg[4])
{
	(void)type;
	if (arg[0] > 0 && arg[0] <= REG_NUMBER)
	{
		DG("VALUE:%i > %i", arg[0], arg[1]);
		set_4byte_value(process, (int)process->pc + \
				(arg[1] % IDX_MOD),
				process->reg[arg[0] - 1]);
		process->carry = 1;
	}
	else
	{
		process->carry = 0;
	}
}

void			vm_mlx_op_st(t_process *process, int type[4], int arg[4])
{
	if (type[1] == T_REG)
	{
		s_if_reg(process, type, arg);
	}
	else
	{
		s_if_not_reg(process, type, arg);
	}
}
