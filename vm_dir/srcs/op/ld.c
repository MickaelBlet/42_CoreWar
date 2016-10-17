/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 09:38:33 by mblet             #+#    #+#             */
/*   Updated: 2016/10/16 18:32:01 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	op_ld(t_process *process, int type[4], int arg[4])
{
	if (arg[1] <= 0 || arg[1] > REG_NUMBER)
	{
		process->carry = 0;
		return ;
	}
	if (type[0] == T_IND)
		process->reg[arg[1] - 1] = arg[0] % IDX_MOD;
	else
		process->reg[arg[1] - 1] = arg[0];
	process->carry = 1;
}
