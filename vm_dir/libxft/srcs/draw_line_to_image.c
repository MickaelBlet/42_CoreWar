/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line_to_image.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 00:27:38 by mblet             #+#    #+#             */
/*   Updated: 2016/06/13 12:55:14 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libxft.h"

#include <stdarg.h>

static void		s_print_line(t_libx_img *img,
		int dir[4], int ls[2], int data[5])
{
	int		num;
	int		i;

	num = ls[0] >> 1;
	i = 0;
	while (i < ls[0])
	{
		libx_put_pixel_to_image(img, data[0], data[1], data[4]);
		num += ls[1];
		if (num >= ls[0])
		{
			num -= ls[0];
			data[0] += dir[0];
			data[1] += dir[1];
		}
		else
		{
			data[0] += dir[2];
			data[1] += dir[3];
		}
		++i;
	}
}

static int		*s_set_long_short(int ls[2], int dir[4], int w, int h)
{
	ls[0] = (w < 0) ? w * -1 : w;
	ls[1] = (h < 0) ? h * -1 : h;
	if (ls[0] <= ls[1])
	{
		ls[0] = (h < 0) ? h * -1 : h;
		ls[1] = (w < 0) ? w * -1 : w;
		if (h < 0)
			dir[3] = -1;
		if (h > 0)
			dir[3] = 1;
		dir[2] = 0;
	}
	return (ls);
}

static void		s_set_direction(int dir[4], int w, int h)
{
	dir[0] = 0;
	dir[1] = 0;
	dir[2] = 0;
	dir[3] = 0;
	if (w < 0)
		dir[0] = -1;
	if (w > 0)
		dir[0] = 1;
	if (h < 0)
		dir[1] = -1;
	if (h > 0)
		dir[1] = 1;
	if (w < 0)
		dir[2] = -1;
	if (w > 0)
		dir[2] = 1;
}

static void		s_draw_line(t_libx_img *img, int data[5])
{
	int		w;
	int		h;
	int		dir[4];
	int		ls[2];

	w = data[2] - data[0];
	h = data[3] - data[1];
	s_set_direction(dir, w, h);
	s_set_long_short(ls, dir, w, h);
	s_print_line(img, dir, ls, data);
}

void			libx_draw_line_to_image(t_libx_img *img, ...)
{
	va_list		args;
	int			data[5];
	int			i;

	if (img == NULL)
		return ;
	va_start(args, img);
	i = 0;
	while (i < 5)
	{
		data[i] = (int)va_arg(args, int);
		++i;
	}
	va_end(args);
	s_draw_line(img, data);
	return ;
}
