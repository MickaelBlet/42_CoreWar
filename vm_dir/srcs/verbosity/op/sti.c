/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/22 14:46:22 by mblet             #+#    #+#             */
/*   Updated: 2016/10/22 16:50:17 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	verbose_op_sti(t_process *process, int type[4], int arg[4])
{
	char	str[2][256];

	if (type[1] == T_REG && (arg[1] <= 0 || arg[1] > REG_NUMBER))
		return ;
	if (type[2] == T_REG && (arg[2] <= 0 || arg[2] > REG_NUMBER))
		return ;
	if ((arg[0] <= 0 || arg[0] > REG_NUMBER))
		return ;
	if (type[1] == T_REG)
		ft_sprintf(str[0], "r%i", arg[1]);
	else
		ft_sprintf(str[0], "%i", arg[1]);
	if (type[2] == T_REG)
		ft_sprintf(str[1], "r%i", arg[2]);
	else
		ft_sprintf(str[1], "%i", arg[2]);
	ft_printf("P %4u | %s r%i %s %s\n"
			"       | -> store to %i + %i = %i (with pc and mod %i)\n",
			process->uid, process->op.name,
			arg[0], str[0], str[1],
			arg[1], arg[2], arg[1] + arg[2],
			process->pc + (arg[1] + arg[2]) % IDX_MOD);
}
