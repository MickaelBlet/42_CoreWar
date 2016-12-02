/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 00:03:31 by mblet             #+#    #+#             */
/*   Updated: 2016/11/29 19:00:28 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void		s_sug_type(t_arg arg, t_op op, int index)
{
	char	str[256];

	if (op.type_args[index] & T_REG && op.type_args[index] & T_IND
		&& op.type_args[index] & T_DIR)
		ft_sprintf(str, "%s", "T_REG | T_IND | T_DIR");
	else if (op.type_args[index] & T_REG && op.type_args[index] & T_DIR)
		ft_sprintf(str, "%s", "T_REG | T_DIR");
	else if (op.type_args[index] & T_REG && op.type_args[index] & T_IND)
		ft_sprintf(str, "%s", "T_REG | T_IND");
	else if (op.type_args[index] & T_DIR && op.type_args[index] & T_IND)
		ft_sprintf(str, "%s", "T_DIR | T_IND");
	else if (op.type_args[index] & T_REG)
		ft_sprintf(str, "%s", "T_REG");
	else if (op.type_args[index] & T_IND)
		ft_sprintf(str, "%s", "T_IND");
	else if (op.type_args[index] & T_DIR)
		ft_sprintf(str, "%s", "T_DIR");
	error_print_sug(arg, ERR_OP_BAD_TYPE, str);
}

static void		s_check_types(t_line *line)
{
	int		i;

	i = 0;
	while (i < line->op.nb_args)
	{
		if (line->args[i].type == 0)
			error_print(line->args[i], ERR_OP_BAD_ARG);
		else if (!(line->op.type_args[i] & line->args[i].type))
			s_sug_type(line->args[i], line->op, i);
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
	{
		error_print(line->args[line->nb_args - 1], ERR_OP_TOO_FEW);
		return ;
	}
	else if (line->nb_args > line->op.nb_args)
	{
		error_print(line->args[line->nb_args - 1], ERR_OP_TOO_MANY);
		return ;
	}
	s_check_types(line);
}
