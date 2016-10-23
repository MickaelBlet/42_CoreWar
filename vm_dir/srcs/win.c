/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 18:49:09 by mblet             #+#    #+#             */
/*   Updated: 2016/10/22 13:03:04 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	win(void)
{
	t_listd		*list;
	t_player	*player;
	t_player	*tmp;

	list = sgt_corewar()->players;
	tmp = NULL;
	while (list)
	{
		player = list->data;
		if (tmp == NULL)
			tmp = player;
		else if (player->last_live > tmp->last_live)
			tmp = player;
		list = list->next;
	}
	ft_printf("Contestant %i, \"%s\", has won !\n", -tmp->id, tmp->name);
}
