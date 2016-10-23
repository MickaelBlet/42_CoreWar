/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/21 22:15:08 by mblet             #+#    #+#             */
/*   Updated: 2016/10/22 17:05:44 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	verbose_move(t_process *process, int jump)
{
	int		index;

	if (sgt_corewar()->option.verbose.move == false)
		return ;
	ft_printf("ADV %u (0x%04x -> 0x%04x) ", jump, process->pc,
			(process->pc + jump) % MEM_SIZE);
	index = 0;
	while (index < jump)
	{
		ft_printf("%02x ",
				sgt_corewar()->ram[(process->pc + index) % MEM_SIZE]);
		++index;
	}
	ft_putchar('\n');
}
