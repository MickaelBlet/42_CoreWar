/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pause.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/24 11:10:35 by mblet             #+#    #+#             */
/*   Updated: 2016/10/24 18:08:33 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

#include <time.h>

static void		s_pixel_to_gray(t_libx_img *img, int x, int y)
{
	unsigned int	color;
	char			*i;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	if (img == NULL || x < 0 || y < 0 || x >= img->width || y >= img->height)
		return ;
	i = img->buffer + (x * (img->bits_per_pixel >> 3)
			+ y * img->size_line);
	b = *i++;
	g = *i++;
	r = *i;
	color = ((r + b + g) / 3 + 0x80);
	color = (color > 255) ? 255 : color;
	*i-- = color;
	*i-- = color;
	*i-- = color;
}

void			s_fill_transparent_rect(t_libx_img *img,
		int xy[2], int wh[2])
{
	int		i;
	int		j;

	j = xy[1];
	while (j < xy[1] + wh[1])
	{
		i = xy[0];
		while (i < xy[0] + wh[0])
		{
			s_pixel_to_gray(img, i, j);
			++i;
		}
		++j;
	}
}

void			vm_mlx_draw_pause(void)
{
	static clock_t	t = 0;
	static t_bool	b = false;

	if (t < clock())
	{
		b = !b;
		t = (b == false) ? clock() + 2000000 : clock() + 1000000;
	}
	if (sgt_mlx()->pause == false || sgt_corewar()->run == false || b == false)
		return ;
	s_fill_transparent_rect(sgt_mlx()->img_memory,
			(int[2]){(VM_MEMORY_NB_BYTE_LINE * VM_MEMORY_BYTE_WIDTH + 3) / 2 - 90,
			MEM_SIZE / VM_MEMORY_NB_BYTE_LINE * VM_MEMORY_BYTE_HEIGHT / 2 - 100},
			(int[2]){80, 200});
	s_fill_transparent_rect(sgt_mlx()->img_memory,
			(int[2]){(VM_MEMORY_NB_BYTE_LINE * VM_MEMORY_BYTE_WIDTH + 3) / 2 + 10,
			MEM_SIZE / VM_MEMORY_NB_BYTE_LINE * VM_MEMORY_BYTE_HEIGHT / 2 - 100},
			(int[2]){80, 200});
}
