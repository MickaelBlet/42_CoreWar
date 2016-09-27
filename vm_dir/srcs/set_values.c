/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_values.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 16:45:51 by mblet             #+#    #+#             */
/*   Updated: 2016/09/27 08:35:43 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	set_1byte_value(t_player *player, unsigned char value)
{
	(player->pc + 0)->last_id = (player->pc + 0)->id;
	(player->pc + 0)->id = player->id;
	(player->pc + 0)->index = player->index;
	(player->pc + 0)->data = (unsigned char)(value >> 0x00);
}

void	set_2byte_value(t_player *player, unsigned short value)
{
	(player->pc + 0)->last_id = (player->pc + 0)->id;
	(player->pc + 0)->id = player->id;
	(player->pc + 0)->index = player->index;
	(player->pc + 0)->data = (unsigned char)(value >> 0x08);
	(player->pc + 1)->last_id = (player->pc + 1)->id;
	(player->pc + 1)->id = player->id;
	(player->pc + 1)->index = player->index;
	(player->pc + 1)->data = (unsigned char)(value >> 0x00);
}

void	set_4byte_value(t_player *player, unsigned int value)
{
	(player->pc + 0)->last_id = (player->pc + 0)->id;
	(player->pc + 0)->id = player->id;
	(player->pc + 0)->index = player->index;
	(player->pc + 0)->data = (unsigned char)(value >> 0x18);
	(player->pc + 1)->last_id = (player->pc + 1)->id;
	(player->pc + 1)->id = player->id;
	(player->pc + 1)->index = player->index;
	(player->pc + 1)->data = (unsigned char)(value >> 0x10);
	(player->pc + 2)->last_id = (player->pc + 2)->id;
	(player->pc + 2)->id = player->id;
	(player->pc + 2)->index = player->index;
	(player->pc + 2)->data = (unsigned char)(value >> 0x08);
	(player->pc + 3)->last_id = (player->pc + 3)->id;
	(player->pc + 3)->id = player->id;
	(player->pc + 3)->index = player->index;
	(player->pc + 3)->data = (unsigned char)(value >> 0x00);
}
