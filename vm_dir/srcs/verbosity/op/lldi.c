/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lldi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/22 14:46:22 by mblet             #+#    #+#             */
/*   Updated: 2016/10/28 14:01:53 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	verbose_op_lldi(t_process *process, int type[4], int arg[4])
{
	int		val[2];

	if (type[0] == T_REG)
		val[0] = process->reg[arg[0] - 1];
	else
		val[0] = arg[0];
	if (type[1] == T_REG)
		val[1] = process->reg[arg[1] - 1];
	else
		val[1] = arg[0];
	ft_printf("P %4lu | %s %i %i r%i\n"
			"       | -> load from %i + %i = %i (with pc %li)\n",
			process->uid, process->op.name,
			val[0], val[1], arg[2],
			val[0], val[1], val[0] + val[1],
			process->pc + (val[0] + val[1]));
}
