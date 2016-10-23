/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/21 21:43:23 by mblet             #+#    #+#             */
/*   Updated: 2016/10/22 16:43:33 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	verbose_op(t_process *process, int type[4], int arg[4])
{
	if (sgt_corewar()->option.verbose.op == false)
		return ;
	func_verbose_tab(process->op.op_code - 1)(process, type, arg);
}
