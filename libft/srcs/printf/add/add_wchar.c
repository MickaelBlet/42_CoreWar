/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_wchar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 22:20:33 by mblet             #+#    #+#             */
/*   Updated: 2016/11/10 14:06:59 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	printf_add_wchar(t_printf *t, wchar_t c)
{
	if (c <= 0x7F)
	{
		printf_add_char(t, c);
	}
	else if (c <= 0x7FF)
	{
		printf_add_char(t, (c >> 6) + 0xC0);
		printf_add_char(t, (c & 0x3F) + 0x80);
	}
	else if (c <= 0xFFFF)
	{
		printf_add_char(t, (c >> 12) + 0xE0);
		printf_add_char(t, ((c >> 6) & 0x3F) + 0x80);
		printf_add_char(t, (c & 0x3F) + 0x80);
	}
	else if (c <= 0x10FFFF)
	{
		printf_add_char(t, (c >> 18) + 0xF0);
		printf_add_char(t, ((c >> 12) & 0x3F) + 0x80);
		printf_add_char(t, ((c >> 6) & 0x3F) + 0x80);
		printf_add_char(t, (c & 0x3F) + 0x80);
	}
}
