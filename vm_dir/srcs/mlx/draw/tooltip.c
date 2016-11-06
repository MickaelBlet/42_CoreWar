/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tooltip.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/16 12:58:22 by mblet             #+#    #+#             */
/*   Updated: 2016/11/07 00:28:23 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		s_index(int pc, int x, int y)
{
	char	str[256];

	x = sgt_mlx()->mouse.x + 10 - VM_INFO_WIDTH;
	y = sgt_mlx()->mouse.y + 10;
	if (sgt_mlx()->mouse.x >
			VM_INFO_WIDTH + VM_MEMORY_NB_BYTE_LINE * VM_MEMORY_BYTE_WIDTH -
			VM_TOOLTIP_MINI_WIDTH)
		x -= VM_TOOLTIP_MINI_WIDTH + 20;
	if (sgt_mlx()->mouse.y > MEM_SIZE / VM_MEMORY_NB_BYTE_LINE *
			VM_MEMORY_BYTE_HEIGHT - VM_TOOLTIP_MINI_HEIGHT)
		y -= VM_TOOLTIP_MINI_HEIGHT + 20;
	vm_mlx_draw_rect(sgt_mlx()->img_memory,
			(int[2]){x, y},
			(int[2]){VM_TOOLTIP_MINI_WIDTH, VM_TOOLTIP_MINI_HEIGHT},
			0x999999);
	vm_mlx_draw_fill_transparent_rect(sgt_mlx()->img_memory,
			(int[2]){x, y},
			(int[2]){VM_TOOLTIP_MINI_WIDTH, VM_TOOLTIP_MINI_HEIGHT});
	x += 5;
	y += 2;
	ft_sprintf(str, "%0.4p", pc);
	LIBX_STRING_TO_IMAGE(sgt_mlx()->img_memory, sgt_mlx()->img_font,
			str, x, y, 0xFFFFFF);
}

static void		s_info(int pc, int x, int y)
{
	t_op	op;
	char	str[256];

	x += 5;
	y += 2;
	op = op_tab(sgt_corewar()->ram[pc].data - 1);
	ft_sprintf(str, "%0.4p         op: %5s\n\n%s",
			pc, op.name, vm_mlx_get_info_byte(op, pc));
	LIBX_STRING_TO_IMAGE(sgt_mlx()->img_memory, sgt_mlx()->img_font,
			str, x, y, 0xFFFFFF);
}

static void		s_background(int pc, int x, int y)
{
	if (op_tab(sgt_corewar()->ram[pc].data - 1).name != NULL)
	{
		vm_mlx_draw_rect(sgt_mlx()->img_memory,
				(int[2]){x, y}, (int[2]){VM_TOOLTIP_WIDTH, VM_TOOLTIP_HEIGHT},
				0x999999);
		vm_mlx_draw_fill_transparent_rect(sgt_mlx()->img_memory,
				(int[2]){x, y}, (int[2]){VM_TOOLTIP_WIDTH, VM_TOOLTIP_HEIGHT});
		s_info(pc, x, y);
	}
	else
	{
		s_index(pc, x, y);
	}
}

void			vm_mlx_draw_tooltip(int pc)
{
	int		x;
	int		y;

	if (pc < 0 || pc >= MEM_SIZE)
		return ;
	x = sgt_mlx()->mouse.x + 10 - VM_INFO_WIDTH;
	y = sgt_mlx()->mouse.y + 10;
	if (sgt_mlx()->mouse.x >
			VM_INFO_WIDTH + VM_MEMORY_NB_BYTE_LINE * VM_MEMORY_BYTE_WIDTH -
			VM_TOOLTIP_WIDTH)
		x -= VM_TOOLTIP_WIDTH + 20;
	if (sgt_mlx()->mouse.y > MEM_SIZE / VM_MEMORY_NB_BYTE_LINE *
			VM_MEMORY_BYTE_HEIGHT - VM_TOOLTIP_HEIGHT)
		y -= VM_TOOLTIP_HEIGHT + 20;
	s_background(pc, x, y);
}
