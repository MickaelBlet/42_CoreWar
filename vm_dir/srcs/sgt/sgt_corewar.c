/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sgt_corewar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/07 10:16:20 by mblet             #+#    #+#             */
/*   Updated: 2016/10/17 01:17:17 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void			s_ini_singleton(t_corewar *t)
{
	t->cycle = 0;
	t->cycle_to_die = CYCLE_TO_DIE;
	t->cycle_check = CYCLE_TO_DIE;
	t->files = NULL;
	t->players = NULL;
	t->process = NULL;
	t->dump = -1;
	t->graphic = false;
	t->nb_cycle_per_second = 100000;
	t->run = true;
}

static t_corewar	**s_singleton(void)
{
	static t_corewar	*t = NULL;

	if (t == NULL)
	{
		if ((t = (t_corewar *)malloc(sizeof(t_corewar))) == NULL)
		{
			ft_dprintf(STDERR_FILENO, "Error malloc.\n");
			exit(EXIT_FAILURE);
		}
		s_ini_singleton(t);
	}
	return (&t);
}

t_corewar			**sgt_addr_corewar(void)
{
	return (s_singleton());
}

t_corewar			*sgt_corewar(void)
{
	t_corewar	**t;

	t = sgt_addr_corewar();
	return (*t);
}
