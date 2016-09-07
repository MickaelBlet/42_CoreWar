/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sgt_op_table.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/07 15:23:54 by mblet             #+#    #+#             */
/*   Updated: 2016/09/07 15:24:21 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void			s_ini_singleton(t_corewar *t)
{
	t->players = NULL;
	ft_bzero(t->ram, MEM_SIZE);
}

static t_corewar	**s_singleton(void)
{
	static t_corewar	*t = NULL;

	if (t == NULL)
		s_ini_singleton(t);
	return (&t);
}

t_corewar			**sgt_addr_optable(void)
{
	return (s_singleton());
}

t_corewar			*sgt_optable(void)
{
	t_corewar	**t;

	t = sgt_addr_lemipc();
	return (*t);
}

