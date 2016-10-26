/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 00:03:31 by mblet             #+#    #+#             */
/*   Updated: 2016/10/26 01:48:59 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void		s_check_types(t_line *line)
{
	int		i;

	i = 0;
	while (i < line->op.nb_args)
	{
		if (line->args[i].type == 0)
			error_print(line->args[i], ERR_OP_BAD_ARG);
		else if (!(line->op.type_args[i] & line->args[i].type))
			error_print(line->args[i], ERR_OP_BAD_TYPE);
		else
			op_arg_to_cor(line, &line->args[i]);
		++i;
	}
	op_to_cor(line);
}

void			line_scan_op(t_line *line)
{
	if (line->nb_args == 0)
		return ;
	else if (line->nb_args < line->op.nb_args)
		return (error_print(line->args[line->nb_args - 1], ERR_OP_TOO_FEW));
	else if (line->nb_args > line->op.nb_args)
		return (error_print(line->args[line->nb_args - 1], ERR_OP_TOO_MANY));
	s_check_types(line);
}
