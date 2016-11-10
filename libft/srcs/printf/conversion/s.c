/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/21 16:07:18 by mblet             #+#    #+#             */
/*   Updated: 2016/11/10 16:32:15 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	printf_conversion_big_s(t_printf *t)
{
	wchar_t		*sw;

	sw = VA_ARG(t->args, wchar_t *);
	if (sw == NULL && t->flags.alt == true)
		printf_string(t, ft_strdup(""));
	else if (sw == NULL)
		printf_string(t, ft_strdup("(null)"));
	else
		printf_string(t, printf_wstr_to_str(t, sw));
}

void	printf_conversion_s(t_printf *t)
{
	char	*s;

	if (t->flags.is_long && !t->flags.is_long_double)
		return (printf_conversion_big_s(t));
	s = VA_ARG(t->args, char *);
	if (s == NULL && t->flags.alt == true)
		printf_string(t, ft_strdup(""));
	else if (s == NULL)
		printf_string(t, ft_strdup("(null)"));
	else
		printf_string(t, ft_strdup(s));
}
