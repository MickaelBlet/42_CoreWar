/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/25 21:28:10 by mblet             #+#    #+#             */
/*   Updated: 2016/10/26 00:33:57 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void		s_jump_whitespace(int *column, char *str)
{
	while (str[*column] == ' ' || str[*column] == '\t')
		++(*column);
}

static char		*s_get_first_word(int *column, char *str)
{
	int		start;

	start = *column;
	while (str[*column] != '\0'
		&& str[*column] != ' ' && str[*column] != '\t'
		&& str[*column] != SEPARATOR_CHAR && str[*column] != COMMENT_CHAR)
		++(*column);
	return (ft_strsub(str, start, *column - start));
}

//static void		s_check_nbr_argument(t_line *line, int nb)
//{
//if ((nb + 1) < line->op.nb_args)
//error_print(line->args[nb], ERR_OP_TOO_FEW);
//else if ((nb + 1) > line->op.nb_args)
//error_print(line->args[nb], ERR_OP_TOO_MANY);
//}

static void		s_get_argument(int column, t_line *line)
{
	int		i;

	i = 0;
	while (line->data[column] != '\0')
	{
		s_jump_whitespace(&column, line->data);
		line->args[i].line = line;
		line->args[i].column = column;
		line->args[i].index_cor = sgt_asm()->index_cor;
		line->args[i].data = s_get_first_word(&column, line->data);
		line->args[i].type = op_get_type(line->op, line->args[i].data);
		s_jump_whitespace(&column, line->data);
		if (line->data[column] == '\0' || line->data[column] == COMMENT_CHAR)
			break ;
		else if (line->data[column] == SEPARATOR_CHAR && (++column))
			++i;
		else
		{
			line->args[i].column = line->args[i].column +
				ft_strlen(line->args[i].data);
			line->args[i].data = NULL;
			return (error_print_sug(line->args[i], ERR_OP_SEP, ","));
		}
	}
	line->nb_args = i + 1;
}

void			line_check_op(int column, t_arg arg)
{
	t_line	*line;

	if (op_check_name(arg.data) == false)
	{
		error_print(arg, ERR_OP_UNKNOWN);
		return (ft_strdel(&arg.data));
	}
	line = arg.line;
	line->op = op_get_from_name(arg.data);
	line->index_cor = sgt_asm()->index_cor;
	ft_strdel(&arg.data);
	if (line->data[column] == '\0' || line->data[column] == COMMENT_CHAR)
		return (error_print(arg, ERR_OP_NO_ARG));
	if (line->op.has_pcode)
		sgt_asm()->index_cor += 1;
	sgt_asm()->index_cor += 1;
	s_get_argument(column, line);
}
