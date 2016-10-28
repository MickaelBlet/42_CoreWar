/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   name.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/25 18:55:45 by mblet             #+#    #+#             */
/*   Updated: 2016/10/27 23:05:20 by mblet            ###   ########.fr       */
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

static void		s_set_name_in_header(t_arg arg)
{
	if (ft_strlen(arg.data) > PROG_NAME_LENGTH)
	{
		arg.column += 1;
		error_print(arg, "name is too long");
		return (ft_strdel(&arg.data));
	}
	ft_bzero(sgt_asm()->cor.header.prog_name, PROG_NAME_LENGTH + 1);
	ft_strcpy(sgt_asm()->cor.header.prog_name, arg.data);
	ft_strdel(&arg.data);
}

void			command_name(int column, t_arg arg)
{
	t_arg	name;

	name.line = arg.line;
	name.column = column;
	name.data = NULL;
	if (arg.line->data[column] == '\0')
		return (error_print_sug(name, ERR_CMD_NAME_NO_ARG, "\"argument\""));
	if (arg.line->data[column] != '"')
		return (error_print_sug(name, ERR_CMD_NAME_NO_QUOTE, "\""));
	name.data = s_get_str_in_quote(&column, arg.line->data);
	if (name.data == NULL
		&& (name.column += ft_strlen(arg.line->data + column)))
		return (error_print_sug(name, ERR_CMD_NAME_NO_QUOTE, "\""));
	s_jump_whitespace(&column, arg.line->data);
	if (name.line->data[column] != '\0'
			&& name.line->data[column] != COMMENT_CHAR)
	{
		name.column = column;
		ft_strdel(&name.data);
		return (error_print(name, ERR_CMD_NAME_EXTRA_ARG));
	}
	s_set_name_in_header(name);
}
