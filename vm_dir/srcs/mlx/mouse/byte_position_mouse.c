/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   byte_position_mouse.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/15 17:39:59 by mblet             #+#    #+#             */
/*   Updated: 2016/11/07 00:52:58 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		s_draw_rect_position(int pc)
{
	int		x;
	int		y;

	vm_mlx_get_position_memory_from_pc(pc, &x, &y);
	vm_mlx_draw_rect(sgt_mlx()->img_memory, (int[2]){x, y},
			(int[2]){VM_MEMORY_BYTE_WIDTH, VM_MEMORY_BYTE_HEIGHT}, 0xFFFFFF);
}

void			byte_position_mouse(void)
{
	int		pc;

	if (sgt_mlx()->mouse.x > VM_INFO_WIDTH
		&& sgt_mlx()->mouse.x <= VM_INFO_WIDTH +
			VM_MEMORY_NB_BYTE_LINE * VM_MEMORY_BYTE_WIDTH
		&& sgt_mlx()->mouse.y > VM_MEMORY_D_HEIGHT + 1
		&& sgt_mlx()->mouse.y < MEM_SIZE / VM_MEMORY_NB_BYTE_LINE *
			VM_MEMORY_BYTE_HEIGHT + VM_MEMORY_D_HEIGHT)
	{
		pc = (sgt_mlx()->mouse.y - VM_MEMORY_D_HEIGHT - 1) /
			VM_MEMORY_BYTE_HEIGHT *
			VM_MEMORY_NB_BYTE_LINE + (sgt_mlx()->mouse.x - VM_INFO_WIDTH - 3) /
			VM_MEMORY_BYTE_WIDTH;
		s_draw_rect_position(pc);
		vm_mlx_draw_tooltip(pc);
	}
}
