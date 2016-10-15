/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/15 14:38:47 by mblet             #+#    #+#             */
/*   Updated: 2016/10/15 14:41:39 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	vm_mlx_draw_info(void)
{
	char	str[30];

	ft_memcpy(sgt_mlx()->img_info->buffer, sgt_mlx()->background_info,
			sgt_mlx()->img_info->width * sgt_mlx()->img_info->height * \
			(sgt_mlx()->img_info->bits_per_pixel >> 3) * \
			sizeof(unsigned char));
	ft_sprintf(str, "nbr_cycle = %i", sgt_corewar()->nbr_cycles);
	LIBX_STRING_TO_IMAGE(sgt_mlx()->img_info, sgt_mlx()->img_font, str,
			0,
			0, 0xFFFFFF);
}
