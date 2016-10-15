/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rect.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/15 18:29:04 by mblet             #+#    #+#             */
/*   Updated: 2016/10/15 18:33:43 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	vm_mlx_draw_rect(t_libx_img *img, int xy[2], int wh[2],
		int color)
{
	int		i;
	int		j;

	i = xy[0];
	j = xy[1];
	while (i < xy[0] + wh[0])
		libx_put_pixel_to_image(img, i++, j, color);
	--i;
	while (j < xy[1] + wh[1])
		libx_put_pixel_to_image(img, i, j++, color);
	--j;
	while (i > xy[0])
		libx_put_pixel_to_image(img, --i, j, color);
	while (j > xy[1])
		libx_put_pixel_to_image(img, i, --j, color);
}
