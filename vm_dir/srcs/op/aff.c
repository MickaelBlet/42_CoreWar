/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 12:08:55 by mblet             #+#    #+#             */
/*   Updated: 2016/10/30 17:06:17 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	op_aff(t_process *process, int type[4], int arg[4])
{
	(void)type;
	//ft_printf("cycle %i: %i ", sgt_corewar()->cycle, process->uid);
	if (sgt_corewar()->option.verbose.aff == true)
		ft_putchar(process->reg[arg[0] - 1] % 256);
	//ft_putchar('\n');
}
