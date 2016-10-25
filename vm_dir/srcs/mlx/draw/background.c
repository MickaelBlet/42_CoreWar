/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/15 12:37:20 by mblet             #+#    #+#             */
/*   Updated: 2016/10/25 02:14:43 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void			vm_mlx_draw_background_memory(void)
{
	t_vm_mlx	*mlx;

	mlx = sgt_mlx();
	libx_image_fill(mlx->img_memory, 0x000000);
	ft_memcpy(mlx->background_memory, mlx->img_memory->buffer,
			mlx->img_memory->width * mlx->img_memory->height * \
			(mlx->img_memory->bits_per_pixel >> 3) * sizeof(unsigned char));
}

static void		s_info_keys(t_vm_mlx *mlx)
{
	vm_mlx_draw_rect(mlx->img_info,
			(int[2]){10, VM_WIN_HEIGHT - 120},
			(int[2]){VM_INFO_WIDTH - 20, 110}, 0xBBBBBB);
	LIBX_STRING_TO_IMAGE(sgt_mlx()->img_info, sgt_mlx()->img_font,
			"{space} : Run / Pause                {esc}   : Exit\n"
			"{s}     : Step by Step\n"
			"{+/=}   : Add 50 cycles / second\n"
			"{_/-}   : Sub 50 cycles / second\n"
			"{(/9}   : Add 10 cycles / second\n"
			"{)/0}   : Sub 10 cycles / second",
			20, VM_WIN_HEIGHT - 110, 0x222222);
}

static void		s_info_players(t_vm_mlx *mlx)
{
	t_listd		*list;
	int			h;

	h = 100;
	list = sgt_corewar()->players;
	while (list)
	{
		LIBX_DRAW_SQUARE_TO_IMAGE(mlx->img_info,
				10, h, VM_INFO_WIDTH - 20, 80, 0x000000);
		h += 90;
		list = list->next;
	}
}

void			vm_mlx_draw_background_info(void)
{
	t_vm_mlx	*mlx;

	mlx = sgt_mlx();
	libx_image_fill(mlx->img_info, 0xECECEC);
	vm_mlx_draw_rect(mlx->img_info,
			(int[2]){10, 10}, (int[2]){VM_INFO_WIDTH - 20, 80}, 0xBBBBBB);
	s_info_players(mlx);
	s_info_keys(mlx);
	ft_memcpy(mlx->background_info, mlx->img_info->buffer,
			mlx->img_info->width * mlx->img_info->height * \
			(mlx->img_info->bits_per_pixel >> 3) * sizeof(unsigned char));
}
