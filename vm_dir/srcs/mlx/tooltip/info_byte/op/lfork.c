/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lfork.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 12:08:45 by mblet             #+#    #+#             */
/*   Updated: 2016/10/15 23:13:42 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	vm_mlx_op_lfork(t_process *process, int type[4], int arg[4])
{
	t_process		*new;
	unsigned short	addr;

	(void)type;
	addr = (process->pc + (arg[0])) % MEM_SIZE;
	if ((new = process_fork(process, addr)) == NULL)
	{
		process->carry = 0;
		return ;
	}
	ft_lstd_push_front(&sgt_corewar()->process, new);
	process->carry = 1;
}
