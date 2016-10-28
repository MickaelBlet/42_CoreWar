/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sgt_dasm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/28 19:51:40 by mblet             #+#    #+#             */
/*   Updated: 2016/10/28 21:43:15 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dasm.h"

static void		s_ini_singleton(t_dasm *t)
{
	t->index_cor = 0;
	ft_bzero(t->file.data, CHAMP_MAX_SIZE + sizeof(t_header));
	t->data = NULL;
	t->lines = NULL;
}

static t_dasm	**s_singleton(void)
{
	static t_dasm	*t = NULL;

	if (t == NULL)
	{
		if ((t = (t_dasm *)malloc(sizeof(t_dasm))) == NULL)
		{
			ft_dprintf(STDERR_FILENO, "Error malloc.\n");
			exit(EXIT_FAILURE);
		}
		s_ini_singleton(t);
	}
	return (&t);
}

t_dasm			**sgt_addr_dasm(void)
{
	return (s_singleton());
}

t_dasm			*sgt_dasm(void)
{
	t_dasm	**t;

	t = sgt_addr_dasm();
	return (*t);
}
