/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lldi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 12:08:36 by mblet             #+#    #+#             */
/*   Updated: 2016/10/28 01:37:07 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	op_lldi(t_process *process, int type[4], int arg[4])
{
	int		val[2];

	val[0] = (type[0] == T_REG) ? process->reg[arg[0] - 1] : arg[0];
	val[1] = (type[1] == T_REG) ? process->reg[arg[1] - 1] : arg[1];
	process->reg[arg[2] - 1] = get_dir_value(process->pc +
			((val[0] + val[1])));
	process->carry = (process->reg[arg[2] - 1] == 0);
}
