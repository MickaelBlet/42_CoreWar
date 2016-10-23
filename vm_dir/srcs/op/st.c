/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 12:04:49 by mblet             #+#    #+#             */
/*   Updated: 2016/10/24 00:35:29 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	op_st(t_process *process, int type[4], int arg[4])
{
	if (type[1] == T_REG)
		set_4byte_value(process, process->pc + process->reg[arg[1] - 1],
				process->reg[arg[0] - 1]);
	else if (type[1] == T_IND)
		set_4byte_value(process, process->pc + (arg[1] % IDX_MOD),
				process->reg[arg[0] - 1]);
	else
		set_4byte_value(process, process->pc + arg[1],
				process->reg[arg[0] - 1]);
}
