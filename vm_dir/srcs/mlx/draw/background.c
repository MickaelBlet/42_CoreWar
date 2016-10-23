/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/15 12:37:20 by mblet             #+#    #+#             */
/*   Updated: 2016/10/18 10:36:41 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	vm_mlx_draw_background_memory(void)
{
	t_vm_mlx	*mlx;

	mlx = sgt_mlx();
	libx_image_fill(mlx->img_memory, 0x000000);
	ft_memcpy(mlx->background_memory, mlx->img_memory->buffer,
			mlx->img_memory->width * mlx->img_memory->height * \
			(mlx->img_memory->bits_per_pixel >> 3) * sizeof(unsigned char));
}

void	vm_mlx_draw_background_info(void)
{
	t_vm_mlx	*mlx;

	mlx = sgt_mlx();
	libx_image_fill(mlx->img_info, 0xECECEC);
	vm_mlx_draw_rect(mlx->img_info,
			(int[2]){10, 10}, (int[2]){VM_INFO_WIDTH - 20, 100}, 0xBBBBBB);
	ft_memcpy(mlx->background_info, mlx->img_info->buffer,
			mlx->img_info->width * mlx->img_info->height * \
			(mlx->img_info->bits_per_pixel >> 3) * sizeof(unsigned char));
}
