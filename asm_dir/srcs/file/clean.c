/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/24 23:36:42 by mblet             #+#    #+#             */
/*   Updated: 2016/10/26 03:12:03 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void		s_delete_arg(t_arg *arg)
{
	ft_strdel(&arg->data);
	free(arg);
}

static void		s_delete_line(t_line *line)
{
	int		i;

	i = 0;
	while (i < line->nb_args)
		ft_strdel(&line->args[i++].data);
	ft_strdel(&line->data);
	free(line);
}

static void		s_delete_commands(char *s)
{
	if (s == NULL)
		return ;
	ft_strdel(&s);
}

void			file_clean(void)
{
	ft_lstd_clear(&sgt_asm()->lines, &s_delete_line);
	ft_lstd_clear(&sgt_asm()->labels, &s_delete_arg);
	ft_lstd_clear(&sgt_asm()->commands, &s_delete_commands);
}
