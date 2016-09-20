/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 09:35:43 by mblet             #+#    #+#             */
/*   Updated: 2016/09/20 10:30:44 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	vm_live(int id)
{
	t_player	*player;
	t_listd		*list;

	list = sgt_corewar()->players;
	while (list)
	{
		player = list->data;
		if (player->id == id)
			player->live += 1;
		list = list->next;
	}
}
