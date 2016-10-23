/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 09:54:50 by mblet             #+#    #+#             */
/*   Updated: 2016/10/23 01:12:59 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "corewar.h"

void	op_sti(t_process *process, int type[4], int arg[4])
{
	int		val[2];

	if (type[1] == T_REG && arg[1] > 0 && arg[1] <= REG_NUMBER)
		val[0] = process->reg[arg[1] - 1];
	else
		val[0] = arg[1];
	if (type[2] == T_REG && arg[2] > 0 && arg[2] <= REG_NUMBER)
		val[1] = process->reg[arg[2] - 1];
	else
		val[1] = arg[2];
	if (type[0] == T_REG && arg[0] > 0 && arg[0] <= REG_NUMBER)
	{
		set_4byte_value(process, process->pc + \
				((val[0] + val[1]) % IDX_MOD), process->reg[arg[0] - 1]);
		process->carry = 1;
	}
	else
	{
		process->carry = 0;
	}
}
