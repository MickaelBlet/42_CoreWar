/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color_in_image.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/15 17:45:44 by mblet             #+#    #+#             */
/*   Updated: 2016/06/14 17:41:28 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libxft.h"

#include <stdio.h>

int		libx_get_color_in_image(t_libx_img *img, int x, int y)
{
	int		c;

	if (img == NULL || x < 0 || y < 0 || x >= img->width || y >= img->height)
		return (0);
	c = *(int*)(img->buffer
			+ (x * (img->bits_per_pixel >> 3) + y * img->size_line));
	c = c & 0x00FFFFFF;
	return (c);
}
