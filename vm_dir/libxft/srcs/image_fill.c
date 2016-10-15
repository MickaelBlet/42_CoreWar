/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/20 23:54:19 by mblet             #+#    #+#             */
/*   Updated: 2016/10/14 01:56:27 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libxft.h"

void	libx_image_fill(t_libx_img *img, int c)
{
	int		i;
	int		*ptr;

	if (img == NULL)
		return ;
	i = 0;
	ptr = (int *)img->buffer;
	while (i < img->width * img->height)
	{
		*(ptr + i) = c;
		i += 1;
	}
}
