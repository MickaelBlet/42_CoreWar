/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 09:38:33 by mblet             #+#    #+#             */
/*   Updated: 2016/10/14 00:34:42 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	op_ld(t_process *process, int type[4], int arg[4])
{
	if (arg[1] > 0 && arg[1] <= REG_NUMBER)
	{
		if (type[0] == T_DIR && process->op.has_idx == 1)
			process->reg[arg[1] - 1] = get_dir_value(process->pc + \
					(arg[0] % IDX_MOD));
		else
			process->reg[arg[1] - 1] = get_ind_value(process->pc + \
					(arg[0] % IDX_MOD));
		process->carry = 1;
	}
	else
	{
		process->carry = 0;
	}
}
