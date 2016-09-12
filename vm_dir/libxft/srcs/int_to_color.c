/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_to_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 10:07:27 by mblet             #+#    #+#             */
/*   Updated: 2016/06/14 17:38:35 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libxft.h"

t_libx_color	libx_int_to_color(int color)
{
	t_libx_color	c;

	c = (t_libx_color){
			.r = ((int)color >> 0x10) & 0xFF,
			.g = ((int)color >> 0x08) & 0xFF,
			.b = ((int)color >> 0x00) & 0xFF
			};
	return (c);
}
