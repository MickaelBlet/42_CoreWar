/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ini_cor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 23:24:03 by mblet             #+#    #+#             */
/*   Updated: 2016/11/06 23:29:39 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		ini_cor(void)
{
	sgt_asm()->index_cor = 0;
	sgt_asm()->file_name = NULL;
	sgt_asm()->lines = NULL;
	sgt_asm()->labels = NULL;
	sgt_asm()->errors = NULL;
	sgt_asm()->commands = NULL;
	sgt_asm()->error = false;
	ft_bzero(&sgt_asm()->cor.header, sizeof(t_header));
	ft_bzero(sgt_asm()->cor.data, CHAMP_MAX_SIZE);
	ft_strcpy(sgt_asm()->cor.header.prog_name, "unknown");
	ft_strcpy(sgt_asm()->cor.header.comment, "unknown");
}
