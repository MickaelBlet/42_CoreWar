/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 09:27:06 by mblet             #+#    #+#             */
/*   Updated: 2016/12/21 20:38:15 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		s_ini_func_tab(t_func_op *t)
{
	t[0] = &op_live;
	t[1] = &op_ld;
	t[2] = &op_st;
	t[3] = &op_add;
	t[4] = &op_sub;
	t[5] = &op_and;
	t[6] = &op_or;
	t[7] = &op_xor;
	t[8] = &op_zjmp;
	t[9] = &op_ldi;
	t[10] = &op_sti;
	t[11] = &op_fork;
	t[12] = &op_lld;
	t[13] = &op_lldi;
	t[14] = &op_lfork;
	t[15] = &op_aff;
	t[16] = NULL;
}

t_func_op		func_tab(int index)
{
	static t_func_op	*t = NULL;

	if (t == NULL)
	{
		if ((t = (t_func_op *)malloc(sizeof(t_func_op) * 17)) == NULL)
		{
			ERR("malloc: error.");
			exit(EXIT_FAILURE);
		}
		s_ini_func_tab(t);
	}
	if (index >= 0 && index <= 15)
		return (t[index]);
	return (t[16]);
}
