/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/15 14:38:47 by mblet             #+#    #+#             */
/*   Updated: 2016/10/17 02:06:38 by mblet            ###   ########.fr       */
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
	ft_sprintf(str, "nbr_cycle = %lli", sgt_corewar()->cycle);
	LIBX_STRING_TO_IMAGE(sgt_mlx()->img_info, sgt_mlx()->img_font, str,
			0,
			0, 0xFFFFFF);
	pthread_mutex_lock(&sgt_corewar()->mutex_process);
	ft_sprintf(str, "nbr_process = %i", ft_lstd_size(sgt_corewar()->process));
	pthread_mutex_unlock(&sgt_corewar()->mutex_process);
	LIBX_STRING_TO_IMAGE(sgt_mlx()->img_info, sgt_mlx()->img_font, str,
			0,
			20, 0xFFFFFF);
	ft_sprintf(str, "cycl_to_die = %lli", sgt_corewar()->cycle_to_die);
	LIBX_STRING_TO_IMAGE(sgt_mlx()->img_info, sgt_mlx()->img_font, str,
			0,
			40, 0xFFFFFF);
}
