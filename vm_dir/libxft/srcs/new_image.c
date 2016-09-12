/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/15 16:46:53 by mblet             #+#    #+#             */
/*   Updated: 2016/06/13 05:30:47 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libxft.h"

#include <mlx.h>
#include <stdlib.h>

t_libx_img	*libx_new_image(void *mlx, int width, int height)
{
	t_libx_img	*img;

	if ((img = (t_libx_img *)malloc(sizeof(t_libx_img))) == NULL)
		return (NULL);
	img->width = width;
	img->height = height;
	img->img_ptr = mlx_new_image(mlx, width, height);
	if (img->img_ptr == NULL)
	{
		free(img);
		return (NULL);
	}
	img->buffer = mlx_get_data_addr(img->img_ptr,
			&(img->bits_per_pixel), &(img->size_line), &(img->endian));
	return (img);
}
