/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 12:07:51 by mblet             #+#    #+#             */
/*   Updated: 2016/10/04 23:53:34 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		s_action(t_process *process)
{
	t_process		*new;
	unsigned short	addr;

	addr = (process->pc + (get_dir_value(process->pc) % IDX_MOD));
	addr %= MEM_SIZE;
	if ((new = process_fork(process, addr)) == NULL)
		return ;
	ft_lstd_push_front(&sgt_corewar()->process, new);
}

void			op_fork(t_process *process)
{
	process->pc += REG_CODE;
	s_action(process);
	process->pc += DIR_CODE;
}
