/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_addr_label.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/25 02:47:42 by mblet             #+#    #+#             */
/*   Updated: 2016/10/25 16:21:38 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		label_get_addr(int index, char *name)
{
	t_listd		*list;
	t_arg		*label;

	list = sgt_asm()->labels;
	while (list != NULL)
	{
		label = list->data;
		if (ft_strequ(label->data, name))
			return (label->index_cor - index);
		list = list->next;
	}
	return (0);
}
