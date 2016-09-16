/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/07 10:04:28 by mblet             #+#    #+#             */
/*   Updated: 2016/09/15 20:01:20 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		s_fill_ram(t_player *player)
{
	size_t			i;
	t_arg_type		*index;

	index = player->pc;
	i = sizeof(t_header);
	while (index < player->pc + CHAMP_MAX_SIZE)
	{
		DG("%02x", (unsigned char)player->data[i]);
		*index = (unsigned char)player->data[i];
		++index;
		++i;
	}
}

static t_bool	s_ini_process(void)
{
	t_listd		*player_list;
	t_player	*player;
	int			nb_players;

	player_list = sgt_corewar()->players;
	nb_players = ft_lstd_size(player_list);
	while (player_list)
	{
		player = player_list->data;
		player->pc = sgt_corewar()->ram + (MEM_SIZE / nb_players) * player->id;
		s_fill_ram(player);
		player_list = player_list->next;
	}
	return (true);
}

static t_bool	s_ini_ram(void)
{
	ft_bzero(sgt_corewar()->ram, MEM_SIZE);
	return (true);
}

void			corewar(void)
{
	DGL;
	sgt_mlx()->mlx = mlx_init();
	DGL;
	if (vm_mlx_init() == false)
	{
		ft_dprintf(STDERR_FILENO, "init mlx.\n");
		exit(EXIT_FAILURE);
	}
	s_ini_ram();
	s_ini_process();
	vm_mlx_print();
	mlx_loop(sgt_mlx()->mlx);
}
