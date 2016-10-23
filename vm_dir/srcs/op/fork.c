/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 12:07:51 by mblet             #+#    #+#             */
/*   Updated: 2016/10/24 00:35:31 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	op_fork(t_process *process, int type[4], int arg[4])
{
	t_process		*new;
	unsigned short	addr;

	(void)type;
	addr = (process->pc + (arg[0] % IDX_MOD)) % MEM_SIZE;
	if ((new = process_fork(process, addr)) == NULL)
		return ;
	ft_lstd_push_front(&sgt_corewar()->process, new);
}
