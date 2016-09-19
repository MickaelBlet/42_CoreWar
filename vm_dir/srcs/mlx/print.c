/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/15 12:40:07 by mblet             #+#    #+#             */
/*   Updated: 2016/09/18 03:18:51 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	vm_mlx_print(void)
{
	size_t	i;
	char	*str;
	int		color[7] = (int[7]){0xFFFFFF, VM_COLOR_PLAYER1, VM_COLOR_PLAYER2, VM_COLOR_PLAYER3, VM_COLOR_PLAYER4, VM_COLOR_PLAYER5, VM_COLOR_PLAYER6};

	i = 0;
	libx_image_fill(sgt_mlx()->img_main, 0xECECEC);
	libx_image_fill(sgt_mlx()->img_ram, 0x000000);
	LIBX_DRAW_SQUARE_TO_IMAGE(sgt_mlx()->img_main, 19, 19,
			VM_WIN_WIDTH - 718, VM_WIN_HEIGHT - 38, 0x000000);
	str = NULL;
	while (i < MEM_SIZE)
	{
		ft_asprintf(&str, "%02x", (unsigned char)sgt_corewar()->ram[i].data);
		LIBX_STRING_TO_IMAGE(sgt_mlx()->img_ram, sgt_mlx()->img_font,
				str, i % 64 * 20 + 100, i / 64 * 18, color[sgt_corewar()->ram[i].id]);
		if (i % 64 == 0)
		{
			ft_asprintf(&str, "%010p:", i);
			LIBX_STRING_TO_IMAGE(sgt_mlx()->img_ram, sgt_mlx()->img_font,
					str, 3, i / 64 * 18, 0x555555);
		}
		++i;
	}
	ft_strdel(&str);
	LIBX_IMAGE_TO_IMAGE(sgt_mlx()->img_main, sgt_mlx()->img_ram, 20, 20,
			0, 0, VM_WIN_WIDTH - 720, VM_WIN_HEIGHT - 40);
}
