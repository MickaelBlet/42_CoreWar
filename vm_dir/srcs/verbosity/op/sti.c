/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/22 14:46:22 by mblet             #+#    #+#             */
/*   Updated: 2016/10/28 13:14:46 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	verbose_op_sti(t_process *process, int type[4], int arg[4])
{
	int		val[2];

	if (type[1] == T_REG)
		val[0] = process->reg[arg[1] - 1];
	else
		val[0] = arg[1];
	if (type[2] == T_REG)
		val[1] = process->reg[arg[2] - 1];
	else
		val[1] = arg[2];
	ft_printf("P %4lu | %s r%i %i %i\n"
			"       | -> store to %i + %i = %i (with pc and mod %li)\n",
			process->uid, process->op.name,
			arg[0], val[0], val[1],
			val[0], val[1], val[0] + val[1],
			process->pc + (val[0] + val[1]) % IDX_MOD);
}
