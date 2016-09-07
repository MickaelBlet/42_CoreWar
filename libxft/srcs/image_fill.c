/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/20 23:54:19 by mblet             #+#    #+#             */
/*   Updated: 2016/06/13 15:15:56 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libxft.h"

void	libx_image_fill(t_libx_img *img, int c)
{
	int	x;
	int	y;

	if (img == NULL)
		return ;
	y = 0;
	while (y < img->height)
	{
		x = 0;
		while (x < img->width)
		{
			libx_put_pixel_to_image(img, x, y, c);
			++x;
		}
		++y;
	}
}
