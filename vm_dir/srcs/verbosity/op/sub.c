/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/22 14:46:22 by mblet             #+#    #+#             */
/*   Updated: 2016/10/23 15:51:44 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	verbose_op_sub(t_process *process, int type[4], int arg[4])
{
	(void)type;
	if (arg[0] <= 0 || arg[0] > REG_NUMBER
		|| arg[1] <= 0 || arg[1] > REG_NUMBER
		|| arg[2] <= 0 || arg[2] > REG_NUMBER)
		return ;
	ft_printf("P %4lu | %s r%i r%i r%i\n",
			process->uid, process->op.name,
			arg[0], arg[1], arg[3]);
}
