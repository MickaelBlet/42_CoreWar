/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/24 22:38:29 by mblet             #+#    #+#             */
/*   Updated: 2016/10/26 00:34:07 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_line	*line_creat(int index, char *str)
{
	t_line	*line;

	if (str == NULL)
		return (NULL);
	if ((line = (t_line *)malloc(sizeof(t_line))) == NULL)
		return (NULL);
	line->index = index;
	line->index_cor = 0;
	line->data = str;
	line->op = op_tab(-1);
	line->nb_args = 0;
	return (line);
}
