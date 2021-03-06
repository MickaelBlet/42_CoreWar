/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_same.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/25 03:00:39 by mblet             #+#    #+#             */
/*   Updated: 2016/11/29 15:18:32 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_bool	label_check_same(char *name)
{
	t_listd		*list;
	t_arg		*label;

	list = sgt_asm()->labels;
	while (list != NULL)
	{
		label = list->data;
		if (label != NULL && ft_strequ(label->data, name))
			return (false);
		list = list->next;
	}
	return (true);
}
