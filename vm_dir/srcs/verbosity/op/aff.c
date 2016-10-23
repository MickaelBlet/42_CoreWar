/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/22 14:46:22 by mblet             #+#    #+#             */
/*   Updated: 2016/10/22 16:43:54 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	verbose_op_aff(t_process *process, int type[4], int arg[4])
{
	(void)type;
	if (arg[0] <= 0 || arg[0] > REG_NUMBER)
		return ;
	ft_printf("P %4u | %s r%i",
			process->uid, process->op.name,
			arg[0]);
}
