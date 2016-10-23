/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/22 14:42:29 by mblet             #+#    #+#             */
/*   Updated: 2016/10/22 14:53:08 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	verbose_op_live(t_process *process, int type[4], int arg[4])
{
	(void)type;
	ft_printf("P %4u | %s %i\n",
			process->uid, process->op.name,
			arg[0]);
}
