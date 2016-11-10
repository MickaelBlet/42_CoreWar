/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 16:16:50 by mblet             #+#    #+#             */
/*   Updated: 2016/11/10 16:27:44 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	printf_conversion_big_c(t_printf *t)
{
	printf_wchar(t, VA_ARG(t->args, wchar_t));
}

void	printf_conversion_c(t_printf *t)
{
	if (t->flags.is_long)
		return ((void)printf_conversion_big_c(t));
	printf_char(t, (unsigned char)VA_ARG(t->args, int));
}
