/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_to_image.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/13 03:40:38 by mblet             #+#    #+#             */
/*   Updated: 2016/06/14 17:14:01 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libxft.h"

#include <stdarg.h>

static void		s_put_pixel(t_libx_img *img, t_libx_img *font,
		int data[4], int color)
{
	unsigned char	*c_font;
	unsigned char	*c_img;
	int				i;

	if ((data[0] + data[2]) >= img->width || (data[1] + data[3]) >= img->height
		|| data[2] >= font->width || data[3] >= font->height
		|| data[2] < 0 || data[3] < 0
		|| (data[0] + data[2]) < 0 || (data[1] + data[3]) < 0)
		return ;
	c_font = (unsigned char *)font->buffer +
		data[2] * (font->bits_per_pixel >> 3) +
		data[3] * font->size_line;
	c_img = (unsigned char *)img->buffer +
		(data[0] + data[2]) * (img->bits_per_pixel >> 3) +
		(data[1] + data[3]) * img->size_line;
	i = 0;
	while (i < 3)
	{
		c_img[i] = ((1.0 - c_font[i] / 255.0) * (c_img[i] / 255.0)) * 255.0 +
			(c_font[i] / 255.0 * ((color >> (i * 8)) & 0xFF) / 255.0) * 255.0;
		++i;
	}
}

static void		s_putchar(t_libx_img *img, t_libx_img *font,
		char c, int data[3])
{
	int		i;
	int		j;
	int		tmp[4];

	if ((i = (c - 33) * (font->width / 94)) < 0)
		return ;
	tmp[0] = data[0] - i;
	tmp[1] = data[1];
	while (i < (c - 33) * (font->width / 94) + (font->width / 94))
	{
		j = 0;
		while (j < font->height)
		{
			tmp[2] = i;
			tmp[3] = j;
			s_put_pixel(img, font, tmp, data[2]);
			++j;
		}
		++i;
	}
}

static void		s_putstr(t_libx_img *img, t_libx_img *font,
		const char *str, int data[3])
{
	int		i;
	int		save_x;

	if (str == NULL)
		return ;
	save_x = data[0];
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
		{
			data[0] = save_x;
			data[1] += font->height;
		}
		else if (str[i] >= 32 && str[i] <= 126)
		{
			s_putchar(img, font, str[i], data);
			data[0] += (font->width / 94);
		}
		++i;
	}
}

void			libx_string_to_image(t_libx_img *img, t_libx_img *font,
		const char *str, ...)
{
	va_list		args;
	int			data[4];
	int			i;

	if (img == NULL || font == NULL)
		return ;
	va_start(args, str);
	i = 0;
	while (i < 3)
	{
		data[i] = (int)va_arg(args, int);
		++i;
	}
	va_end(args);
	s_putstr(img, font, str, data);
}
