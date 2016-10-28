/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/29 00:40:40 by mblet             #+#    #+#             */
/*   Updated: 2016/10/29 01:02:46 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dasm.h"

static void		s_delete_line(t_line *line)
{
	free(line);
}

void			file_clean(void)
{
	ft_lstd_clear(&sgt_dasm()->lines, &s_delete_line);
	ft_bzero(sgt_dasm()->file.data, CHAMP_MAX_SIZE + sizeof(t_header));
	sgt_dasm()->index_cor = 0;
	sgt_dasm()->data = NULL;
	sgt_dasm()->lines = NULL;
}
