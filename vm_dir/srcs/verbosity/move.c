/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/21 22:15:08 by mblet             #+#    #+#             */
/*   Updated: 2016/10/23 15:48:01 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	verbose_move(t_process *process, int jump)
{
	int		index;

	if (sgt_corewar()->option.verbose.move == false)
		return ;
	ft_printf("ADV %u (0x%04x -> 0x%04x) ", jump, (int)process->pc,
			(int)(process->pc + jump));
	index = 0;
	while (index < jump)
	{
		ft_printf("%02x ",
				sgt_corewar()->ram[(process->pc + index) % MEM_SIZE].data);
		++index;
	}
	ft_putchar('\n');
}
