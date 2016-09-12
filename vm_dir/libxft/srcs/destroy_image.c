/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 21:39:26 by mblet             #+#    #+#             */
/*   Updated: 2016/06/14 21:48:02 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libxft.h"

#include <mlx.h>
#include <stdlib.h>

void	libx_destroy_image(void *mlx, t_libx_img *img)
{
	mlx_destroy_image(mlx, img->img_ptr);
	free(img);
	img = NULL;
}
