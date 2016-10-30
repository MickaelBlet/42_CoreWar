/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/28 22:33:39 by mblet             #+#    #+#             */
/*   Updated: 2016/10/29 12:00:08 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dasm.h"

t_line	*line_creat(int index_cor, t_op op)
{
	t_line	*line;

	if ((line = (t_line *)malloc(sizeof(t_line))) == NULL)
		return (NULL);
	line->index_cor = index_cor;
	line->op = op;
	line->has_label = false;
	return (line);
}
