/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 12:04:49 by mblet             #+#    #+#             */
/*   Updated: 2016/10/23 19:44:36 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		s_if_reg(t_process *process, int type[4], int arg[4])
{
	(void)type;
	if (type[0] == T_REG && arg[0] > 0 && arg[0] <= REG_NUMBER
		&& arg[1] > 0 && arg[1] <= REG_NUMBER)
	{
		set_4byte_value(process, process->pc + process->reg[arg[1] - 1],
				process->reg[arg[0] - 1]);
	}
}

static void		s_if_not_reg(t_process *process, int type[4], int arg[4])
{
	if (type[0] == T_REG && arg[0] > 0 && arg[0] <= REG_NUMBER)
	{
		if (type[1] == T_IND)
		{
			set_4byte_value(process, process->pc + (arg[1] % IDX_MOD),
					process->reg[arg[0] - 1]);
		}
		else
		{
			set_4byte_value(process, process->pc + arg[1],
					process->reg[arg[0] - 1]);
		}
	}
}

void			op_st(t_process *process, int type[4], int arg[4])
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
