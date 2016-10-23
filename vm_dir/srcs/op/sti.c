/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 09:54:50 by mblet             #+#    #+#             */
/*   Updated: 2016/10/23 19:44:55 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "corewar.h"

void	op_sti(t_process *process, int type[4], int arg[4])
{
	int		val[3];

	if (type[0] != T_REG
		|| (type[0] == T_REG && (arg[0] <= 0 || arg[0] > REG_NUMBER))
		|| (type[1] == T_REG && (arg[1] <= 0 || arg[1] > REG_NUMBER))
		|| (type[2] == T_REG && (arg[2] <= 0 || arg[2] > REG_NUMBER)))
	{
		return ;
	}
	val[0] = (type[0] == T_REG) ? process->reg[arg[0] - 1] : arg[0];
	val[1] = (type[1] == T_REG) ? process->reg[arg[1] - 1] : arg[1];
	val[2] = (type[2] == T_REG) ? process->reg[arg[2] - 1] : arg[2];
	set_4byte_value(process,
			process->pc + ((val[1] + val[2]) % IDX_MOD),
			val[0]);
}
