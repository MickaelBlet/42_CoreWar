/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/07 10:04:28 by mblet             #+#    #+#             */
/*   Updated: 2016/09/19 00:50:00 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
static void		s_fill_ram(t_player *player)
{
	size_t	i;
	t_byte	*index;

	index = player->pc;
	i = sizeof(t_header);
	while (index < player->pc + player->prog_size)
	{
		index->data = (unsigned char)player->data[i];
		index->id = player->id;
		++index;
		++i;
	}
}*/
/*
static t_bool	s_ini_process(void)
{
	t_listd		*player_list;
	t_player	*player;
	int			nb_players;

	player_list = sgt_corewar()->players;
	nb_players = ft_lstd_size(player_list);
	DG("%i", nb_players);
	while (player_list)
	{
		player = player_list->data;
		player->pc = sgt_corewar()->ram +
			(MEM_SIZE / nb_players) * (player->id - 1);
		s_fill_ram(player);
		player_list = player_list->next;
	}
	return (true);
}*/

static t_bool	s_ini_ram(void)
{
	size_t		i;

	i = 0;
	while (i < MEM_SIZE)
	{
		sgt_corewar()->ram[i].data = 0;
		sgt_corewar()->ram[i].id = 0;
		sgt_corewar()->ram[i].last_id = 0;
		++i;
	}
	return (true);
}

void			corewar(int argc, char **argv)
{
	s_ini_ram();
	(void)argc;
	(void)argv;
	if (vm_mlx_init() == false)
	{
		ft_dprintf(STDERR_FILENO, "init mlx.\n");
		exit(EXIT_FAILURE);
	}
	vm_mlx_print();
	mlx_loop(sgt_mlx()->mlx);
}
