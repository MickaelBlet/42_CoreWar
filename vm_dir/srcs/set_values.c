/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_values.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 16:45:51 by mblet             #+#    #+#             */
/*   Updated: 2016/09/26 17:45:35 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	set_1byte_value(t_player *player, unsigned char value)
{
	(player->pc + sizeof(t_byte) * 0)->last_id = \
		(player->pc + sizeof(t_byte) * 0)->id;
	(player->pc + sizeof(t_byte) * 0)->id = player->id;
	(player->pc + sizeof(t_byte) * 0)->index = player->index;
	(player->pc + sizeof(t_byte) * 0)->data = (unsigned char)(value >> 0x00);
}

void	set_2byte_value(t_player *player, unsigned short value)
{
	(player->pc + sizeof(t_byte) * 0)->last_id = \
		(player->pc + sizeof(t_byte) * 0)->id;
	(player->pc + sizeof(t_byte) * 0)->id = player->id;
	(player->pc + sizeof(t_byte) * 0)->index = player->index;
	(player->pc + sizeof(t_byte) * 0)->data = (unsigned char)(value >> 0x08);
	(player->pc + sizeof(t_byte) * 1)->last_id = \
		(player->pc + sizeof(t_byte) * 1)->id;
	(player->pc + sizeof(t_byte) * 1)->id = player->id;
	(player->pc + sizeof(t_byte) * 1)->index = player->index;
	(player->pc + sizeof(t_byte) * 1)->data = (unsigned char)(value >> 0x00);
}

void	set_4byte_value(t_player *player, unsigned int value)
{
	(player->pc + sizeof(t_byte) * 0)->last_id = \
		(player->pc + sizeof(t_byte) * 0)->id;
	(player->pc + sizeof(t_byte) * 0)->id = player->id;
	(player->pc + sizeof(t_byte) * 0)->index = player->index;
	(player->pc + sizeof(t_byte) * 0)->data = (unsigned char)(value >> 0x18);
	(player->pc + sizeof(t_byte) * 1)->last_id = \
		(player->pc + sizeof(t_byte) * 1)->id;
	(player->pc + sizeof(t_byte) * 1)->id = player->id;
	(player->pc + sizeof(t_byte) * 1)->index = player->index;
	(player->pc + sizeof(t_byte) * 1)->data = (unsigned char)(value >> 0x10);
	(player->pc + sizeof(t_byte) * 2)->last_id = \
		(player->pc + sizeof(t_byte) * 2)->id;
	(player->pc + sizeof(t_byte) * 2)->id = player->id;
	(player->pc + sizeof(t_byte) * 2)->index = player->index;
	(player->pc + sizeof(t_byte) * 2)->data = (unsigned char)(value >> 0x08);
	(player->pc + sizeof(t_byte) * 3)->last_id = \
		(player->pc + sizeof(t_byte) * 3)->id;
	(player->pc + sizeof(t_byte) * 3)->id = player->id;
	(player->pc + sizeof(t_byte) * 3)->index = player->index;
	(player->pc + sizeof(t_byte) * 3)->data = (unsigned char)(value >> 0x00);
}
