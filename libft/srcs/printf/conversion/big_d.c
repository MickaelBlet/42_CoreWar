/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 14:55:44 by mblet             #+#    #+#             */
/*   Updated: 2016/11/10 15:14:59 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	printf_conversion_big_d(t_printf *t)
{
	long long int	signed_number;

	t->flags.base = 10;
	signed_number = VA_ARG(t->args, long int);
	t->flags.is_negative = signed_number < 0;
	if (t->flags.is_negative)
		t->flags.number.longlong = signed_number * -1;
	else
		t->flags.number.longlong = signed_number;
	printf_number(t);
}
