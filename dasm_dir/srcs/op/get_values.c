/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_values.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 10:39:04 by mblet             #+#    #+#             */
/*   Updated: 2016/10/28 23:02:19 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dasm.h"

int		get_reg_value(size_t index)
{
	return ((unsigned char)(sgt_dasm()->data[(index + 0) % CHAMP_MAX_SIZE]));
}

int		get_ind_value(size_t index)
{
	int		ret;

	ret = 0;
	ret |= (unsigned char)sgt_dasm()->data[(index + 0) % CHAMP_MAX_SIZE];
	ret = ret << 0x8;
	ret |= (unsigned char)sgt_dasm()->data[(index + 1) % CHAMP_MAX_SIZE];
	return ((short)ret);
}

int		get_dir_value(size_t index)
{
	int		ret;

	ret = 0;
	ret |= (unsigned char)sgt_dasm()->data[(index + 0) % CHAMP_MAX_SIZE];
	ret = ret << 0x8;
	ret |= (unsigned char)sgt_dasm()->data[(index + 1) % CHAMP_MAX_SIZE];
	ret = ret << 0x8;
	ret |= (unsigned char)sgt_dasm()->data[(index + 2) % CHAMP_MAX_SIZE];
	ret = ret << 0x8;
	ret |= (unsigned char)sgt_dasm()->data[(index + 3) % CHAMP_MAX_SIZE];
	return (ret);
}

int		get_value_from_type(size_t index, int type, int has_idx)
{
	if (type == T_REG)
		return (get_reg_value(index));
	if (type == T_IND)
		return (get_ind_value(index));
	if (type == T_DIR && has_idx == 1)
		return (get_ind_value(index));
	if (type == T_DIR)
		return (get_dir_value(index));
	return (0);
}
