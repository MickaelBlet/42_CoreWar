/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/24 21:53:54 by mblet             #+#    #+#             */
/*   Updated: 2016/10/26 00:46:26 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void		s_print_sugestion(t_arg arg, const char *sug)
{
	int		i;
	char	str_cpy[ft_strlen(arg.line->data) + 1];
	char	sugestion[ft_strlen(sug) + 1];

	ft_strcpy(str_cpy, arg.line->data);
	ft_strcpy(sugestion, sug);
	i = 0;
	while (str_cpy[i] && i < arg.column)
	{
		if (arg.line->data[i] != '\t')
			str_cpy[i] = ' ';
		++i;
	}
	str_cpy[i] = '\0';
	ft_dprintf(STDERR_FILENO, "%s{bold}{green}%s{reset}\n",
			str_cpy, sugestion);
}

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

void			error_print(t_arg arg, const char *str)
{
	ft_dprintf(STDERR_FILENO,
			"{bold}%s:%lu:%lu: {red}error:{reset} {bold}%s{reset}\n",
			sgt_asm()->file_name, arg.line->index + 1, arg.column + 1, str);
	ft_dprintf(STDERR_FILENO, "%s\n", arg.line->data);
	s_print_indicator(arg);
	sgt_asm()->error = true;
}

void			error_print_sug(t_arg arg, const char *str, const char *sug)
{
	ft_dprintf(STDERR_FILENO,
			"{bold}%s:%lu:%lu: {red}error:{reset} {bold}%s{reset}\n",
			sgt_asm()->file_name, arg.line->index + 1, arg.column + 1, str);
	ft_dprintf(STDERR_FILENO, "%s\n", arg.line->data);
	s_print_indicator(arg);
	s_print_sugestion(arg, sug);
	sgt_asm()->error = true;
}
