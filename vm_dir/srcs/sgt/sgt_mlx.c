/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sgt_mlx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/15 11:05:53 by mblet             #+#    #+#             */
/*   Updated: 2016/09/15 16:23:09 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void			s_ini_singleton(t_vm_mlx *t)
{
	t->mlx = NULL;
	t->win = NULL;
	t->font = NULL;
	t->main = NULL;
	t->ram = NULL;
}

static t_vm_mlx		**s_singleton(void)
{
	static t_vm_mlx		*t = NULL;

	if (t == NULL)
	{
		if ((t = (t_vm_mlx *)malloc(sizeof(t_vm_mlx))) == NULL)
		{
			ft_dprintf(STDERR_FILENO, "Error malloc.\n");
			exit(EXIT_FAILURE);
		}
		s_ini_singleton(t);
	}
	return (&t);
}

t_vm_mlx			**sgt_addr_mlx(void)
{
	return (s_singleton());
}

t_vm_mlx			*sgt_mlx(void)
{
	t_vm_mlx	**t;

	t = sgt_addr_mlx();
	return (*t);
}
