/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 18:49:09 by mblet             #+#    #+#             */
/*   Updated: 2016/10/23 17:39:05 by mblet            ###   ########.fr       */
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
		if (player->id == sgt_corewar()->id_last_live)
		{
			tmp = player;
			break ;
		}
		list = list->next;
	}
	if (tmp == NULL)
		ft_printf("All contestant, has lose !\n");
	else
		ft_printf("Contestant %i, \"%s\", has won !\n", -tmp->id, tmp->name);
}
