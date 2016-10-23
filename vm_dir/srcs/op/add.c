/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 12:05:19 by mblet             #+#    #+#             */
/*   Updated: 2016/10/24 00:35:32 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	op_add(t_process *process, int type[4], int arg[4])
{
	(void)type;
	process->reg[arg[2] - 1] = process->reg[arg[0] - 1] +
		process->reg[arg[1] - 1];
	process->carry = (process->reg[arg[2] - 1] == 0);
}
