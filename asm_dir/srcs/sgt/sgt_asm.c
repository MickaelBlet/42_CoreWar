/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sgt_asm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/24 21:32:44 by mblet             #+#    #+#             */
/*   Updated: 2016/10/24 23:35:38 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void		s_ini_singleton(t_asm *t)
{
	(void)t;
}

static t_asm	**s_singleton(void)
{
	static t_asm	*t = NULL;

	if (t == NULL)
	{
		if ((t = (t_asm *)malloc(sizeof(t_asm))) == NULL)
		{
			ft_dprintf(STDERR_FILENO, "Error malloc.\n");
			exit(EXIT_FAILURE);
		}
		s_ini_singleton(t);
	}
	return (&t);
}

t_asm			**sgt_addr_asm(void)
{
	return (s_singleton());
}

t_asm			*sgt_asm(void)
{
	t_asm	**t;

	t = sgt_addr_asm();
	return (*t);
}
