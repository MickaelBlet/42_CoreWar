/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 09:35:43 by mblet             #+#    #+#             */
/*   Updated: 2016/09/27 19:56:58 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	vm_live(t_player *player)
{
	t_player	*p;
	t_listd		*list;
	int			id;

		DGL;
	id = get_ind_value(player->pc + 1);
		DGL;
	list = sgt_corewar()->players;
		DGL;
	while (list)
	{
		p = list->data;
		if (p->id == id)
			p->live += 1;
		list = list->next;
	}
	player->pc += 5;
}
