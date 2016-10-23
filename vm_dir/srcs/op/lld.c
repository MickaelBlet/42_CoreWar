/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lld.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 12:08:17 by mblet             #+#    #+#             */
/*   Updated: 2016/10/24 00:35:30 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	op_lld(t_process *process, int type[4], int arg[4])
{
	if (type[0] == T_DIR)
		process->reg[arg[1] - 1] = get_dir_value(process->pc +
				(arg[0]));
	else
		process->reg[arg[1] - 1] = get_ind_value(process->pc +
				(arg[0]));
	process->carry = (process->reg[arg[1] - 1] == 0);
}
