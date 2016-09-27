/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_values.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 16:45:51 by mblet             #+#    #+#             */
/*   Updated: 2016/09/27 19:46:58 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	set_1byte_value(t_player *player, t_byte *b, unsigned char value)
{
	(b + 0)->modified = 1;
	(b + 0)->id = player->id;
	(b + 0)->index = player->index;
	(b + 0)->data = (unsigned char)(value >> 0x00);
}

void	set_2byte_value(t_player *player, t_byte *b, unsigned short value)
{
	(b + 0)->modified = 1;
	(b + 1)->modified = 1;
	(b + 0)->id = player->id;
	(b + 1)->id = player->id;
	(b + 0)->index = player->index;
	(b + 1)->index = player->index;
	(b + 0)->data = (unsigned char)(value >> 0x08);
	(b + 1)->data = (unsigned char)(value >> 0x00);
}

void	set_4byte_value(t_player *player, t_byte *b, unsigned int value)
{
	(b + 0)->modified = 1;
	(b + 1)->modified = 1;
	(b + 2)->modified = 1;
	(b + 3)->modified = 1;
	(b + 0)->id = player->id;
	(b + 1)->id = player->id;
	(b + 2)->id = player->id;
	(b + 3)->id = player->id;
	(b + 0)->index = player->index;
	(b + 1)->index = player->index;
	(b + 2)->index = player->index;
	(b + 3)->index = player->index;
	(b + 0)->data = (unsigned char)(value >> 0x18);
	(b + 1)->data = (unsigned char)(value >> 0x10);
	(b + 2)->data = (unsigned char)(value >> 0x08);
	(b + 3)->data = (unsigned char)(value >> 0x00);
}
