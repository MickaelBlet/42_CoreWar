/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   warning.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/25 18:12:55 by mblet             #+#    #+#             */
/*   Updated: 2016/10/25 19:19:29 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void		s_print_indicator(t_arg arg)
{
	int		i;
	char	str_cpy[ft_strlen(arg.line->data) + 1];
	char	indicator[ft_strlen(arg.data) + 2];

	ft_strcpy(str_cpy, arg.line->data);
	ft_bzero(indicator, ft_strlen(arg.data) + 2);
	ft_memset(indicator, '~', ft_strlen(arg.data));
	indicator[0] = '^';
	i = 0;
	while (str_cpy[i] && i < arg.column)
	{
		if (arg.line->data[i] != '\t')
			str_cpy[i] = ' ';
		++i;
	}
	str_cpy[i] = '\0';
	ft_dprintf(STDERR_FILENO, "%s{bold}{green}%s{reset}\n",
			str_cpy, indicator);
}

void			warning_print(t_arg arg, const char *str)
{
	ft_dprintf(STDERR_FILENO,
			"{bold}%s:%lu:%lu: {magenta}warning:{reset} {bold}%s{reset}\n",
			sgt_asm()->file_name, arg.line->index + 1, arg.column + 1, str);
	ft_dprintf(STDERR_FILENO, "%s\n", arg.line->data);
	s_print_indicator(arg);
}
