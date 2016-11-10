/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/21 23:28:08 by mblet             #+#    #+#             */
/*   Updated: 2016/11/10 15:18:31 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	printf_conversion_p(t_printf *t)
{
	const void	*ptr;

	ptr = VA_ARG(t->args, void *);
	if (t->flags.prec == 0 && ptr == NULL)
	{
		t->flags.prec = -1;
		t->flags.pad = ' ';
		printf_string(t, ft_strdup("0x"));
		return ;
	}
	t->flags.base = 16;
	t->flags.number.word = (unsigned long int)ptr;
	t->flags.is_negative = false;
	t->flags.alt = true;
	t->flags.spec = 'x';
	printf_number(t);
}
