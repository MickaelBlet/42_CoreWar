/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/15 11:11:46 by mblet             #+#    #+#             */
/*   Updated: 2016/10/15 18:37:37 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		s_convert_byte_to_hex(char *ret, unsigned char byte)
{
	ret[0] = (byte / 0x10) % 0x10;
	ret[1] = byte % 0x10;
	ret[0] += (ret[0] > 9) ? 'A' - 10 : '0';
	ret[1] += (ret[1] > 9) ? 'A' - 10 : '0';
	ret[2] = '\0';
}

static void		s_draw_process_pc(void)
{
	t_listd		*list;
	t_process	*process;
	int			x;
	int			y;

	list = sgt_corewar()->process;
	while (list != NULL)
	{
		process = list->data;
		x = process->pc % VM_MEMORY_NB_BYTE_LINE * VM_MEMORY_BYTE_WIDTH - 1;
		y = process->pc / VM_MEMORY_NB_BYTE_LINE * VM_MEMORY_BYTE_HEIGHT;
		vm_mlx_draw_rect(sgt_mlx()->img_memory, (int[2]){x, y},
				(int[2]){VM_MEMORY_BYTE_WIDTH, VM_MEMORY_BYTE_HEIGHT},
				sgt_mlx()->color[process->color_id]);
		list = list->next;
	}
}

void			vm_mlx_draw_memory(void)
{
	size_t	i;
	int		color;
	char	str[BUFF_SIZE];

	ft_memcpy(sgt_mlx()->img_memory->buffer, sgt_mlx()->background_memory,
			sgt_mlx()->img_memory->width * sgt_mlx()->img_memory->height * \
			(sgt_mlx()->img_memory->bits_per_pixel >> 3) * \
			sizeof(unsigned char));
	s_draw_process_pc();
	i = 0;
	while (i < MEM_SIZE)
	{
		s_convert_byte_to_hex(str, sgt_corewar()->ram[i].data);
		color = sgt_mlx()->color[sgt_corewar()->ram[i].color_id];
		if (sgt_corewar()->ram[i].modified_cycle > \
				(int)(sgt_corewar()->nbr_cycles - 100))
			color += VM_COLOR_BOLD;
		LIBX_STRING_TO_IMAGE(sgt_mlx()->img_memory, sgt_mlx()->img_font, str,
				i % VM_MEMORY_NB_BYTE_LINE * VM_MEMORY_BYTE_WIDTH + 2,
				i / VM_MEMORY_NB_BYTE_LINE * VM_MEMORY_BYTE_HEIGHT + 1, color);
		++i;
	}
	byte_position_mouse();
}
