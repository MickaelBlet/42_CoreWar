/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 09:27:06 by mblet             #+#    #+#             */
/*   Updated: 2016/09/26 09:44:21 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		s_ini_func_tab(t_func_op **t)
{
	(*t)[0] = &vm_live;
	(*t)[1] = &vm_ld;
	//(*t)[2] = &vm_st;
	//(*t)[3] = &vm_add;
	//(*t)[4] = &vm_sub;
	//(*t)[5] = &vm_and;
	//(*t)[6] = &vm_or;
	//(*t)[7] = &vm_xor;
	//(*t)[8] = &vm_zjmp;
	//(*t)[9] = &vm_ldi;
	//(*t)[10] = &vm_sti;
	//(*t)[11] = &vm_fork;
	//(*t)[12] = &vm_lld;
	//(*t)[13] = &vm_lldi;
	//(*t)[14] = &vm_lfork;
	//(*t)[15] = &vm_aff;
	(*t)[16] = NULL;
}

t_func_op		*func_tab(int index)
{
	static t_func_op	**t = NULL;

	if (t == NULL)
	{
		if ((t = (t_func_op **)malloc(sizeof(t_func_op *) * 17)) == NULL)
		{
			ERR("malloc: error.");
			exit(EXIT_FAILURE);
		}
		s_ini_func_tab(&t);
	}
	if (index >= 0 && index <= 15)
		return (t[index]);
	return (t[16]);
}
