/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel_to_image.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/15 16:58:30 by mblet             #+#    #+#             */
/*   Updated: 2016/06/13 05:31:21 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libxft.h"

void	libx_put_pixel_to_image(t_libx_img *img, int x, int y, int c)
{
	char	*ptr_color;

	if (img == NULL || x < 0 || y < 0 || x >= img->width || y >= img->height)
		return ;
	ptr_color = img->buffer + (x * (img->bits_per_pixel >> 3)
			+ y * img->size_line);
	ptr_color[0] = (c >> 0x00) & 0xFF;
	ptr_color[1] = (c >> 0x08) & 0xFF;
	ptr_color[2] = (c >> 0x10) & 0xFF;
}
