/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label_scan.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/25 21:21:45 by mblet             #+#    #+#             */
/*   Updated: 2016/10/26 19:25:15 by mblet            ###   ########.fr       */
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
		&& str[*column] != COMMENT_CHAR
		&& str[*column] != COMMENT_CHAR_BASIC)
		++(*column);
	return (ft_strsub(str, start, *column - start));
}

void			line_label_scan(int column, t_line *line)
{
	t_arg	arg;

	s_jump_whitespace(&column, line->data);
	if (line->data[column] == COMMENT_CHAR
		|| line->data[column] == COMMENT_CHAR_BASIC
		|| line->data[column] == '\0')
		return ;
	arg.line = line;
	arg.column = column;
	arg.data = s_get_first_word(&column, line->data);
	s_jump_whitespace(&column, line->data);
	line_check_op(column, arg);
}
