/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_values.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 10:39:04 by mblet             #+#    #+#             */
/*   Updated: 2016/10/04 19:58:46 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		get_reg_value(size_t index)
{
	return ((unsigned int)(sgt_corewar()->ram[index % MEM_SIZE]->data));
}

int		get_dir_value(size_t index)
{
	int		ret;

	ret = 0x0;
	ret += sgt_corewar()->ram[(index + 0) % MEM_SIZE]->data;
	ret *= 0x10;
	ret += sgt_corewar()->ram[(index + 1) % MEM_SIZE]->data;
	return (ret);
}

int		get_ind_value(size_t index)
{
	int		ret;

	ret = 0x0;
	ret += sgt_corewar()->ram[(index + 0) % MEM_SIZE]->data;
	ret *= 0x10;
	ret += sgt_corewar()->ram[(index + 1) % MEM_SIZE]->data;
	ret *= 0x10;
	ret += sgt_corewar()->ram[(index + 2) % MEM_SIZE]->data;
	ret *= 0x10;
	ret += sgt_corewar()->ram[(index + 3) % MEM_SIZE]->data;
	return (ret);
}
