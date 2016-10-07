/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_values.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 16:45:51 by mblet             #+#    #+#             */
/*   Updated: 2016/10/04 20:09:00 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	set_1byte_value(t_process *process, size_t index, unsigned char value)
{
	sgt_corewar()->ram[index % MEM_SIZE]->data = value;
	sgt_corewar()->ram[index % MEM_SIZE]->color_id = process->color_id;
	sgt_corewar()->ram[index % MEM_SIZE]->modified = true;
	sgt_corewar()->ram[index % MEM_SIZE]->live = false;
}

void	set_2byte_value(t_process *process, size_t index, unsigned short value)
{
	set_1byte_value(process, index + 0, value >> 0x08);
	set_1byte_value(process, index + 1, value >> 0x00);
}

void	set_4byte_value(t_process *process, size_t index, unsigned int value)
{
	set_1byte_value(process, index + 0, value >> 0x18);
	set_1byte_value(process, index + 1, value >> 0x10);
	set_1byte_value(process, index + 2, value >> 0x08);
	set_1byte_value(process, index + 3, value >> 0x00);
}
