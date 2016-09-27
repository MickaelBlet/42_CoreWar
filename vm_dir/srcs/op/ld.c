/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 09:38:33 by mblet             #+#    #+#             */
/*   Updated: 2016/09/27 12:00:45 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		s_action(t_player *player, int type[4])
{
	t_byte	*b;
	int		val0;
	int		val1;

	b = player->pc + 1;
	if (type[0] == T_LAB)
	{
		val0 = get_ind_value(b);
		b += 4;
	}
	else if (type[0] == T_DIR)
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
	byte_code_to_type(&types, (player->pc + 1)->data);
	if (!(types[0] == T_DIR || types[0] == T_LAB) || types[1] != T_REG)
		player->carry = 1;
	else
	{
		if (types[0] == T_LAB)
			size += 4;
		if (types[0] == T_DIR)
			size += 2;
		size += 1;
		s_action(player, types);
	}
	player->pc += size;
}
