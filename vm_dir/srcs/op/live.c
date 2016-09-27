/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 09:35:43 by mblet             #+#    #+#             */
/*   Updated: 2016/09/27 11:57:23 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	vm_live(t_player *player)
{
	t_player	*p;
	t_listd		*list;
	int			id;

	id = (int)(player->pc + 1);
	list = sgt_corewar()->players;
	while (list)
	{
		p = list->data;
		if (p->id == id)
			p->live += 1;
		list = list->next;
	}
	player->pc += 5;
}
