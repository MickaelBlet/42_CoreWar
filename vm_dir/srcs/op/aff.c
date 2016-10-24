/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 12:08:55 by mblet             #+#    #+#             */
/*   Updated: 2016/10/24 01:00:58 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	op_aff(t_process *process, int type[4], int arg[4])
{
	(void)type;
	if (sgt_corewar()->option.verbose.aff == true)
		ft_putchar(process->reg[arg[0] - 1] % 256);
}
