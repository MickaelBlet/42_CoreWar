/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tooltip.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/16 12:58:22 by mblet             #+#    #+#             */
/*   Updated: 2016/10/22 23:50:18 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		s_info(int pc, int x, int y)
{
	t_op	op;
	char	str[250];

	x += 5;
	y += 2;
	op = op_tab(sgt_corewar()->ram[pc].data - 1);
	ft_sprintf(str, "index: 0x%04x op: %-5s code: %02x\n\n%6s%9s%9s\n%08x %08x %08x",
			pc, op.name, op.op_code, "T_REG", "T_REG", "T_REG",
			0, 0, 0);
	LIBX_STRING_TO_IMAGE(sgt_mlx()->img_memory, sgt_mlx()->img_font,
			str, x, y, 0xFFFFFF);
}

static void		s_background(int x, int y)
{
	vm_mlx_draw_rect(sgt_mlx()->img_memory,
			(int[2]){x, y}, (int[2]){VM_TOOLTIP_WIDTH, VM_TOOLTIP_HEIGHT},
			0x999999);
	vm_mlx_draw_fill_transparent_rect(sgt_mlx()->img_memory,
			(int[2]){x, y}, (int[2]){VM_TOOLTIP_WIDTH, VM_TOOLTIP_HEIGHT});
}

void			vm_mlx_draw_tooltip(int pc)
{
	int		x;
	int		y;

	if (pc >= MEM_SIZE || op_tab(sgt_corewar()->ram[pc].data - 1).name == NULL)
		return ;
	x = sgt_mlx()->mouse.x + 10 - VM_INFO_WIDTH;
	y = sgt_mlx()->mouse.y + 10;
	if (sgt_mlx()->mouse.x > \
			VM_INFO_WIDTH + VM_MEMORY_NB_BYTE_LINE * VM_MEMORY_BYTE_WIDTH -
			VM_TOOLTIP_WIDTH)
		x -= VM_TOOLTIP_WIDTH + 20;
	if (sgt_mlx()->mouse.y > MEM_SIZE / VM_MEMORY_NB_BYTE_LINE *
			VM_MEMORY_BYTE_HEIGHT + VM_MEMORY_D_HEIGHT - VM_TOOLTIP_HEIGHT)
		y -= VM_TOOLTIP_HEIGHT + 20;
	s_background(x, y);
	s_info(pc, x, y);
}
