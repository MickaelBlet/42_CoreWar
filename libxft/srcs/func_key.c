/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/13 06:07:03 by mblet             #+#    #+#             */
/*   Updated: 2016/06/13 08:38:40 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libxft.h"

#include <stdlib.h>

static t_libx_key_func	*s_singleton(void)
{
	static t_libx_key_func	f[0x200] = {0};

	return (f);
}

static void				s_putnbr_hex(int key)
{
	if (key < 10)
	{
		key = '0' + key;
		write(2, &key, 1);
	}
	else if (key < 16)
	{
		key = 'A' + key - 10;
		write(2, &key, 1);
	}
	else if (key >= 16)
	{
		s_putnbr_hex(key / 16);
		s_putnbr_hex(key % 16);
	}
}

void					libx_hook_key(int key, void *e)
{
	if (key >= 0 && key < 0x200 && s_singleton()[key] != NULL)
		s_singleton()[key](e);
	else
	{
		write(2, "0x", 2);
		s_putnbr_hex(key);
		write(2, ": \033[38;5;124mthis key is not assigned.\033[0m\n", 44);
	}
}

void					libx_func_key(int key, t_libx_key_func f)
{
	if (s_singleton() != NULL)
		s_singleton()[key] = f;
}
