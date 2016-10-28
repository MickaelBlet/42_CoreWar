/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/24 21:53:54 by mblet             #+#    #+#             */
/*   Updated: 2016/10/26 23:55:40 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void		s_print_sugestion(char **error, t_arg arg, const char *sug)
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
	ft_asprintf(error, "%#s%s{bold}{green}%s{reset}\n", *error,
			str_cpy, sugestion);
}

static void		s_print_indicator(char **error, t_arg arg)
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
	ft_asprintf(error, "%#s%s{bold}{green}%s{reset}\n", *error,
			str_cpy, indicator);
}

static int		s_cond(t_error *e1, t_error *e2)
{
	if (e1->line < e2->line)
		return (0);
	else if (e1->line == e2->line && e1->column < e2->column)
		return (0);
	return (1);
}

void			error_print(t_arg arg, const char *str)
{
	t_error		*error;

	if ((error = (t_error *)malloc(sizeof(t_error))) == NULL)
		return ;
	error->line = arg.line->index + 1;
	error->column = arg.column + 1;
	error->str = NULL;
	ft_asprintf(&error->str,
			"{bold}%s:%lu:%lu: {red}error:{reset} {bold}%s{reset}\n",
			sgt_asm()->file_name, arg.line->index + 1, arg.column + 1, str);
	ft_asprintf(&error->str, "%#s%s\n", error->str, arg.line->data);
	s_print_indicator(&error->str, arg);
	ft_lstd_push_cond(&sgt_asm()->errors, error, &s_cond);
	sgt_asm()->error = true;
}

void			error_print_sug(t_arg arg, const char *str, const char *sug)
{
	t_error		*error;

	if ((error = (t_error *)malloc(sizeof(t_error))) == NULL)
		return ;
	error->line = arg.line->index + 1;
	error->column = arg.column + 1;
	error->str = NULL;
	ft_asprintf(&error->str,
			"{bold}%s:%lu:%lu: {red}error:{reset} {bold}%s{reset}\n",
			sgt_asm()->file_name, arg.line->index + 1, arg.column + 1, str);
	ft_asprintf(&error->str, "%#s%s\n", error->str, arg.line->data);
	s_print_indicator(&error->str, arg);
	s_print_sugestion(&error->str, arg, sug);
	ft_lstd_push_cond(&sgt_asm()->errors, error, &s_cond);
	sgt_asm()->error = true;
}
