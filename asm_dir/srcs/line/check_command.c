/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/25 16:24:55 by mblet             #+#    #+#             */
/*   Updated: 2016/10/28 00:24:12 by mblet            ###   ########.fr       */
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
		&& str[*column] != LABEL_CHAR && str[*column] != SEPARATOR_CHAR
		&& str[*column] != COMMENT_CHAR && str[*column] != QUOTE_CHAR
		&& str[*column] != COMMENT_CHAR_BASIC)
		++(*column);
	return (ft_strsub(str, start, *column - start));
}

void			line_check_command(int column, t_line *line)
{
	t_arg	arg;

	arg.line = line;
	arg.column = column;
	arg.data = s_get_first_word(&column, line->data);
	if (command_check_same(arg.data) == false)
	{
		error_print(arg, ERR_CMD_SAME);
		return (ft_strdel(&arg.data));
	}
	ft_lstd_push_front(&sgt_asm()->commands, arg.data);
	s_jump_whitespace(&column, line->data);
	if (ft_strequ(arg.data, NAME_CMD_STRING))
		command_name(column, arg);
	else if (ft_strequ(arg.data, COMMENT_CMD_STRING))
		command_comment(column, arg);
	else if (line->data[column] == '\0' || line->data[column] == COMMENT_CHAR
		|| line->data[column] == COMMENT_CHAR_BASIC)
		warning_print(arg, WAR_CMD_UNKNOWN);
	else
	{
		arg.column = column;
		ft_strdel(&arg.data);
		error_print(arg, ERR_CMD_EXTRA_ARG);
	}
}
