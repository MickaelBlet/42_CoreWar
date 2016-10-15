/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 12:08:55 by mblet             #+#    #+#             */
/*   Updated: 2016/10/13 18:09:18 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	op_aff(t_process *process, int type[4], int arg[4])
{
	(void)type;
	if (arg[0] > 0 && arg[0] <= REG_NUMBER)
	{
		ft_putchar(process->reg[arg[0] - 1] % 256);
		process->carry = 1;
	}
	else
	{
		process->carry = 0;
	}
}
