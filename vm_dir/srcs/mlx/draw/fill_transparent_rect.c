/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_transparent_rect.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/15 18:45:55 by mblet             #+#    #+#             */
/*   Updated: 2016/10/15 19:11:09 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		s_pixel_to_gray(t_libx_img *img, int x, int y)
{
	unsigned int	color;
	char			*i;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	if (img == NULL || x < 0 || y < 0 || x >= img->width || y >= img->height)
		return ;
	i = img->buffer + (x * (img->bits_per_pixel >> 3)
			+ y * img->size_line);
	b = *i++;
	g = *i++;
	r = *i;
	color = (r + b + g) / 5;
	*i-- = color;
	*i-- = color;
	*i-- = color;
}

void			vm_mlx_draw_fill_transparent_rect(t_libx_img *img,
		int xy[2], int wh[2])
{
	int		i;
	int		j;

	j = xy[1];
	while (j < xy[1] + wh[1])
	{
		i = xy[0];
		while (i < xy[0] + wh[0])
		{
			s_pixel_to_gray(img, i, j);
			++i;
		}
		++j;
	}
}
