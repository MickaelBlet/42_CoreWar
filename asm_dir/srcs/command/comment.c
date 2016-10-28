/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comment.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/25 18:55:45 by mblet             #+#    #+#             */
/*   Updated: 2016/10/28 00:25:54 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void		s_jump_whitespace(int *column, char *str)
{
	while (str[*column] == ' ' || str[*column] == '\t')
		++(*column);
}

static char		*s_get_str_in_quote(int *column, char *str)
{
	char	*ret;
	char	quote;

	quote = str[*column];
	if (ft_strchr(str + *column + 1, quote) == NULL)
		return (NULL);
	ret = ft_strsub(str + *column, 1,
			ft_strchr(str + *column + 1, quote) - (str + *column) - 1);
	if (ret == NULL)
		ret = ft_strdup("");
	*column += ft_strchr(str + *column + 1, quote) - (str + *column) + 1;
	return (ret);
}

static void		s_set_comment_in_header(t_arg arg)
{
	if (ft_strlen(arg.data) > COMMENT_LENGTH)
	{
		arg.column += 1;
		error_print(arg, "comment is too long");
		return (ft_strdel(&arg.data));
	}
	ft_bzero(sgt_asm()->cor.header.comment, COMMENT_LENGTH + 1);
	ft_strcpy(sgt_asm()->cor.header.comment, arg.data);
	ft_strdel(&arg.data);
}

void			command_comment(int column, t_arg arg)
{
	t_arg	comment;

	comment.line = arg.line;
	comment.column = column;
	comment.data = NULL;
	if (arg.line->data[column] == '\0')
		return (error_print_sug(comment, ERR_CMD_COM_NO_ARG, "\"argument\""));
	if (arg.line->data[column] != '"')
		return (error_print_sug(comment, ERR_CMD_COM_NO_QUOTE, "\""));
	comment.data = s_get_str_in_quote(&column, arg.line->data);
	if (comment.data == NULL
		&& (comment.column += ft_strlen(arg.line->data + column)))
		return (error_print_sug(comment, ERR_CMD_COM_NO_QUOTE, "\""));
	s_jump_whitespace(&column, arg.line->data);
	if (comment.line->data[column] != '\0'
		&& comment.line->data[column] != COMMENT_CHAR)
	{
		comment.column = column;
		ft_strdel(&comment.data);
		return (error_print(comment, ERR_CMD_COM_EXTRA_ARG));
	}
	s_set_comment_in_header(comment);
}
