/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/15 14:38:47 by mblet             #+#    #+#             */
/*   Updated: 2016/10/18 19:20:07 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		s_general(char *str)
{
	ft_sprintf(str, "Cycle        : %-8lli     " \
			"Next check   : %8lli\n" \
			"Cycle to die : %-8lli     " \
			"Cycle delta  : %8lli\n\n" \
			"Process      : %u",
			sgt_corewar()->cycle,
			sgt_corewar()->last_cycle_check + sgt_corewar()->cycle_to_die,
			sgt_corewar()->cycle_to_die,
			CYCLE_DELTA,
			ft_lstd_size(sgt_corewar()->process));
}

void			vm_mlx_draw_info(void)
{
	char	str[1024];

	ft_memcpy(sgt_mlx()->img_info->buffer, sgt_mlx()->background_info,
			sgt_mlx()->img_info->width * sgt_mlx()->img_info->height * \
			(sgt_mlx()->img_info->bits_per_pixel >> 3) * sizeof(unsigned char));
	s_general(str);
	LIBX_STRING_TO_IMAGE(sgt_mlx()->img_info, sgt_mlx()->img_font, str,
			20,
			20, 0x333333);
}
