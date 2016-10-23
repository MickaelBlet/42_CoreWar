/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/15 11:11:46 by mblet             #+#    #+#             */
/*   Updated: 2016/10/18 19:46:07 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		s_convert_byte_to_hex(char *ret, unsigned char byte)
{
	ret[0] = (byte / 0x10) % 0x10;
	ret[1] = byte % 0x10;
	ret[0] += (ret[0] > 9) ? 'a' - 10 : '0';
	ret[1] += (ret[1] > 9) ? 'a' - 10 : '0';
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
		x = process->pc % VM_MEMORY_NB_BYTE_LINE * VM_MEMORY_BYTE_WIDTH + 2;
		y = process->pc / VM_MEMORY_NB_BYTE_LINE * VM_MEMORY_BYTE_HEIGHT;
		vm_mlx_draw_rect(sgt_mlx()->img_memory, (int[2]){x, y},
				(int[2]){VM_MEMORY_BYTE_WIDTH, VM_MEMORY_BYTE_HEIGHT},
				sgt_mlx()->color[process->color_id]);
		list = list->next;
	}
}

static void		s_draw_live(size_t i)
{
	LIBX_DRAW_CIRCLE_TO_IMAGE(sgt_mlx()->img_memory,
			i % VM_MEMORY_NB_BYTE_LINE * VM_MEMORY_BYTE_WIDTH + 3,
			i / VM_MEMORY_NB_BYTE_LINE * VM_MEMORY_BYTE_HEIGHT,
			VM_MEMORY_BYTE_HEIGHT, VM_MEMORY_BYTE_HEIGHT,
			sgt_mlx()->color[sgt_corewar()->ram[i].color_id]);
	LIBX_STRING_TO_IMAGE(sgt_mlx()->img_memory, sgt_mlx()->img_font,
			"01", i % VM_MEMORY_NB_BYTE_LINE * VM_MEMORY_BYTE_WIDTH + 5,
			i / VM_MEMORY_NB_BYTE_LINE * VM_MEMORY_BYTE_HEIGHT + 1,
			0x000000);
}

static void		*s_thread(void *e)
{
	size_t	i;
	int		color;
	char	str[3];

	i = *((size_t *)e);
	while (i < MEM_SIZE)
	{
		s_convert_byte_to_hex(str, sgt_corewar()->ram[i].data);
		color = sgt_mlx()->color[sgt_corewar()->ram[i].color_id];
		if (sgt_corewar()->ram[i].modified_cycle > \
				(int)(sgt_corewar()->cycle - CYCLE_DELTA))
			color += VM_COLOR_BOLD;
		if (sgt_corewar()->ram[i].live >
				(int)(sgt_corewar()->cycle - sgt_corewar()->nb_cycle_per_second)
			&& sgt_corewar()->ram[i].live > 0)
			s_draw_live(i);
		else
			LIBX_STRING_TO_IMAGE(sgt_mlx()->img_memory, sgt_mlx()->img_font,
					str, i % VM_MEMORY_NB_BYTE_LINE * VM_MEMORY_BYTE_WIDTH + 5,
					i / VM_MEMORY_NB_BYTE_LINE * VM_MEMORY_BYTE_HEIGHT + 1,
					color);
		i += 32;
	}
	return (NULL);
}

void			vm_mlx_draw_memory(void)
{
	size_t		i;
	size_t		t[32];
	pthread_t	thread[32];

	ft_memcpy(sgt_mlx()->img_memory->buffer, sgt_mlx()->background_memory,
			sgt_mlx()->img_memory->width * sgt_mlx()->img_memory->height * \
			(sgt_mlx()->img_memory->bits_per_pixel >> 3) * \
			sizeof(unsigned char));
	s_draw_process_pc();
	i = 0;
	while (i < 32)
	{
		t[i] = i;
		if ((pthread_create(&thread[i], NULL, &s_thread, &t[i]) < 0))
			exit(EXIT_FAILURE);
		i++;
	}
	i = 0;
	while (i < 32)
	{
		pthread_join(thread[i], (void *)&t[i]);
		++i;
	}
	byte_position_mouse();
}
