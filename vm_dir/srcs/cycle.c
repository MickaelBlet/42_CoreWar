/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/16 23:28:58 by mblet             #+#    #+#             */
/*   Updated: 2016/10/26 21:31:30 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		s_reset_live_player(t_corewar *c)
{
	t_listd		*list_players;
	t_player	*player;

	list_players = c->players;
	while (list_players)
	{
		player = list_players->data;
		player->live = 0;
		list_players = list_players->next;
	}
}

static size_t	s_get_nb_live(t_corewar *c)
{
	size_t		live;
	t_listd		*list_players;
	t_player	*player;

	live = 0;
	list_players = c->players;
	while (list_players && live < NBR_LIVE)
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
	if (s_get_nb_live(c) < NBR_LIVE && (++c->cycle_check) <= MAX_CHECKS)
		return ;
	c->cycle_check = 0;
	c->cycle_to_die -= CYCLE_DELTA;
	s_reset_live_player(c);
	verbose_cycle_to_die();
}

static void		s_dump(void)
{
	if (sgt_corewar()->option.dump >= 0 && (sgt_corewar()->option.dump--) == 0)
	{
		dump();
		exit(EXIT_FAILURE);
	}
}

void			cycle(void)
{
	t_listd		*list_process;
	size_t		nb_process;

	list_process = sgt_corewar()->process;
	if (list_process == NULL)
	{
		sgt_corewar()->run = false;
		return ;
	}
	++sgt_corewar()->cycle;
	s_dump();
	verbose_cycle();
	nb_process = 0;
	while (list_process)
	{
		process_action(list_process->data);
		list_process = list_process->next;
		++nb_process;
	}
	sgt_corewar()->nb_process = nb_process;
	s_check_cycle(sgt_corewar());
}
