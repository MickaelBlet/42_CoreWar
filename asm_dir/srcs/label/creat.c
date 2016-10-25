/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/25 02:34:57 by mblet             #+#    #+#             */
/*   Updated: 2016/10/25 02:55:34 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_label		*label_creat(int index, char *name)
{
	t_label		*label;

	if ((label = (t_label *)malloc(sizeof(t_label))) == NULL)
		return (NULL);
	label->index = index;
	label->name = name;
	return (label);
}
