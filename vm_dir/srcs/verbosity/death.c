/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/21 21:53:50 by mblet             #+#    #+#             */
/*   Updated: 2016/10/23 15:49:51 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	verbose_death(t_process *process)
{
	if (sgt_corewar()->option.verbose.death == false)
		return ;
	ft_printf("Process %lu hasn't lived for %li cycles (CTD %li)\n",
			process->uid,
			sgt_corewar()->cycle - process->live,
			sgt_corewar()->cycle_to_die);
}
