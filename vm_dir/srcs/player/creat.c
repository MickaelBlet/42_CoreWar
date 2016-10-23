/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 00:47:55 by mblet             #+#    #+#             */
/*   Updated: 2016/10/21 23:31:10 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_player	*player_creat(t_file *file, int color_id)
{
	t_player	*player;

	if ((player = (t_player *)malloc(sizeof(t_player))) == NULL)
		return (NULL);
	player->id = file->id;
	player->color_id = color_id;
	player->live = 0;
	player->last_live = -1;
	player->name = file->header->prog_name;
	player->description = file->header->comment;
	ft_printf("* Player %i, weighing %i bytes, \"%s\" (\"%s\") !\n",
			-player->id, file->header->prog_size,
			player->name, player->description);
	return (player);
}
