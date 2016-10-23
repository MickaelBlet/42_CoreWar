/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle_to_die.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/21 17:05:44 by mblet             #+#    #+#             */
/*   Updated: 2016/10/22 13:19:28 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	verbose_cycle_to_die(void)
{
	if (sgt_corewar()->option.verbose.cycle == false)
		return ;
	ft_printf("Cycle to die is now %lli\n", sgt_corewar()->cycle_to_die);
}
