/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xor.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 12:06:37 by mblet             #+#    #+#             */
/*   Updated: 2016/10/13 17:08:43 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	op_xor(t_process *process, int type[4], int arg[4])
{
	int		val[2];

	if (type[0] == T_REG && arg[0] > 0 && arg[0] <= REG_NUMBER)
		val[0] = process->reg[arg[0] - 1];
	else
		val[0] = arg[0];
	if (type[1] == T_REG && arg[1] > 0 && arg[1] <= REG_NUMBER)
		val[1] = process->reg[arg[1] - 1];
	else
		val[1] = arg[1];
	if (arg[2] > 0 && arg[2] <= REG_NUMBER)
	{
		process->reg[arg[2] - 1] = val[0] ^ val[1];
		process->carry = 1;
	}
	else
	{
		process->carry = 0;
	}
}
