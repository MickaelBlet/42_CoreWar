/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/22 14:46:22 by mblet             #+#    #+#             */
/*   Updated: 2016/10/22 16:25:20 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	verbose_op_fork(t_process *process, int type[4], int arg[4])
{
	(void)type;
	ft_printf("P %4u | %s %i (%i)\n",
			process->uid, process->op.name,
			arg[0], process->pc + (arg[0] % IDX_MOD));
}
