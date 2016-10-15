/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjmp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 12:06:59 by mblet             #+#    #+#             */
/*   Updated: 2016/10/13 23:26:40 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	op_zjmp(t_process *process, int type[4], int arg[4])
{
	(void)type;
	if (process->carry == 1)
	{
		process->pc = (process->pc + arg[0] - 3) % MEM_SIZE;
	}
}
