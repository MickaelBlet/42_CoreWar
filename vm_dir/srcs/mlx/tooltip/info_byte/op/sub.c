/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 12:05:34 by mblet             #+#    #+#             */
/*   Updated: 2016/10/15 23:15:01 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	vm_mlx_op_sub(t_process *process, int type[4], int arg[4])
{
	(void)type;
	if (arg[0] > 0 && arg[0] <= REG_NUMBER
		&& arg[1] > 0 && arg[1] <= REG_NUMBER
		&& arg[2] > 0 && arg[2] <= REG_NUMBER)
	{
		process->reg[arg[2] - 1] = process->reg[arg[0] - 1] - \
			process->reg[arg[1] - 1];
		process->carry = 1;
	}
	else
	{
		process->carry = 0;
	}
}
