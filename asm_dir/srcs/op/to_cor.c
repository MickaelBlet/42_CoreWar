/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_cor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 01:00:59 by mblet             #+#    #+#             */
/*   Updated: 2016/10/28 04:04:01 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	s_get_pcode(t_line *line)
{
	unsigned char	pcode;
	int				i;

	i = 0;
	pcode = 0;
	while (i <= MAX_ARGS_NUMBER)
	{
		if (i >= line->op.nb_args)
			pcode |= 0;
		else if (line->args[i].type == T_REG)
			pcode |= 1;
		else if (line->args[i].type == T_DIR)
			pcode |= 2;
		else if (line->args[i].type == T_IND)
			pcode |= 3;
		if (i <= MAX_ARGS_NUMBER - 2)
			pcode = pcode << 2;
		++i;
	}
	return (pcode);
}

void		op_to_cor(t_line *line)
{
	sgt_asm()->cor.data[(line->index_cor) % CHAMP_MAX_SIZE] = line->op.op_code;
	if (line->op.has_pcode)
		sgt_asm()->cor.data[(line->index_cor + 1) % CHAMP_MAX_SIZE] =
			s_get_pcode(line);
}
