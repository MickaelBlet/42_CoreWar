/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 09:38:33 by mblet             #+#    #+#             */
/*   Updated: 2016/09/26 15:00:18 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		s_action(t_player *player, int type[4])
{
	t_byte			*b;
	unsigned int	val0;

	b = player->pc + 1;
	if (type[0] == T_LAB)
	{
		val0 = get_lab_value(b);
		b += 4;
	}
	else (type[0] == T_DIR)
	{
		val0 = get_dir_value(b);
		b += 2;
	}
	val1 = get_reg_value(b);
	if (val1 >= REG_NUMBER)
		player->carry = 1;
	else
		player->reg[val1] = val0;
}

void			vm_ld(t_player *player)
{
	int		types[4];
	size_t	size;

	size = 1;
	byte_code_to_type(&type, player->pc + 1);
	if (!(type[0] == T_DIR || type[0] == T_LAB) || type[1] != T_REG)
		player->carry = 1;
	else
	{
		if (type[0] == T_LAB)
			size += 4;
		if (type[0] == T_DIR)
			size += 2;
		size += 1;
		s_action(player, type);
	}
	player->pc += size;
}
