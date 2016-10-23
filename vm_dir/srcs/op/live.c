/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 09:35:43 by mblet             #+#    #+#             */
/*   Updated: 2016/10/24 00:35:30 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	op_live(t_process *process, int type[4], int arg[4])
{
	t_listd		*list;
	t_player	*player;

	(void)type;
	list = sgt_corewar()->players;
	process->live = sgt_corewar()->cycle;
	while (list != NULL)
	{
		player = list->data;
		if (player == NULL || player->id != arg[0])
		{
			list = list->next;
			continue ;
		}
		verbose_live(-arg[0], player->name);
		player->live += 1;
		player->last_live = sgt_corewar()->cycle;
		sgt_corewar()->id_last_live = arg[0];
		sgt_corewar()->ram[process->pc].color_id = player->color_id;
		sgt_corewar()->ram[process->pc].live = sgt_corewar()->cycle;
		return ;
	}
}
