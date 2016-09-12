/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_to_image.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/15 17:26:23 by mblet             #+#    #+#             */
/*   Updated: 2016/06/13 15:46:51 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libxft.h"

#include <stdarg.h>

static void		s_image_to_image(t_libx_img *dst, t_libx_img *src, int data[4])
{
	int		x[2];
	int		y[2];

	y[0] = data[1];
	x[1] = data[2];
	y[1] = data[3];
	data[4] = (data[4] > 0) ? data[4] : src->width - x[1];
	data[5] = (data[5] > 0) ? data[5] : src->height - y[1];
	while (y[0] < data[1] + data[5])
	{
		x[0] = data[0];
		while (x[0] < data[0] + data[4])
		{
			libx_put_pixel_to_image(dst, x[0], y[0],
					libx_get_color_in_image(src,
						x[0] - data[0] + x[1],
						y[0] - data[1] + y[1]));
			++x[0];
		}
		++y[0];
	}
}

void			libx_image_to_image(t_libx_img *dst, t_libx_img *src,
		...)
{
	va_list		args;
	int			data[6];
	int			i;

	if (dst == NULL || src == NULL)
		return ;
	va_start(args, src);
	i = 0;
	while (i < 6)
	{
		data[i] = (int)va_arg(args, int);
		++i;
	}
	va_end(args);
	s_image_to_image(dst, src, data);
}
