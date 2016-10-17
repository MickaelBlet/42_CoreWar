/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/16 23:28:58 by mblet             #+#    #+#             */
/*   Updated: 2016/10/17 00:20:52 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static size_t	s_get_nb_live(t_corewar *c)
{
	size_t		live;
	t_listd		*list_players;
	t_player	*player;

	live = 0;
	list_players = c->players;
	while (list_players)
	{
		player = list_players->data;
		live += player->live;
		list_players = list_players->next;
	}
	return (live);
}

static void		s_check_cycle(t_corewar *c)
{
	if (c->cycle < (c->last_cycle_check + c->cycle_to_die))
		return ;
	process_check_live();
	c->last_cycle_check = c->cycle;
	if (s_get_nb_live(c) < NBR_LIVE && (c->cycle_check++) < MAX_CHECKS)
		return ;
	c->cycle_check = 0;
	c->cycle_to_die -= CYCLE_DELTA;
}

static void		s_dump(void)
{
	if (sgt_corewar()->dump >= 0 && (sgt_corewar()->dump--) == 0)
	{
		dump();
		sleep(2);
		exit(EXIT_FAILURE);
	}
}

void			cycle(void)
{
	t_listd		*list_process;

	++sgt_corewar()->cycle;
	s_check_cycle(sgt_corewar());
	list_process = sgt_corewar()->process;
	while (list_process)
	{
		process_action(list_process->data);
		list_process = list_process->next;
	}
	s_dump();
}
