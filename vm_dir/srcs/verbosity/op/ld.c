/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/22 14:46:22 by mblet             #+#    #+#             */
/*   Updated: 2016/10/22 14:54:17 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	verbose_op_ld(t_process *process, int type[4], int arg[4])
{
	int		val;

	if (arg[1] <= 0 || arg[1] > REG_NUMBER)
		return ;
	if (type[0] == T_IND)
		val = arg[0] % IDX_MOD;
	else
		val = arg[0];
	ft_printf("P %4u | %s %i r%i\n",
			process->uid, process->op.name,
			val, arg[1]);
}
