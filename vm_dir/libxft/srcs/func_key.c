/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/13 06:07:03 by mblet             #+#    #+#             */
/*   Updated: 2016/10/16 00:57:47 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libxft.h"

#include <stdlib.h>

static t_libx_key_func	*s_singleton(int flag)
{
	static t_libx_key_func	f_press[0x200] = {0};
	static t_libx_key_func	f_release[0x200] = {0};

	if (flag == 0)
		return (f_press);
	else
		return (f_release);
}

int						libx_hook_key_press(int key, void *e)
{
	if (key >= 0 && key < 0x200 && s_singleton(0)[key] != NULL)
	{
		s_singleton(0)[key](e);
		return (1);
	}
	return (0);
}

int						libx_hook_key_release(int key, void *e)
{
	if (key >= 0 && key < 0x200 && s_singleton(1)[key] != NULL)
	{
		s_singleton(1)[key](e);
		return (1);
	}
	return (0);
}

void					libx_func_key(int key, int flag, t_libx_key_func f)
{
	if ((flag == 0 || flag == 1) && s_singleton(flag) != NULL)
		s_singleton(flag)[key] = f;
}
