/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/28 23:33:09 by mblet             #+#    #+#             */
/*   Updated: 2016/11/21 10:57:15 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dasm.h"

static void		s_arg(t_line *line, int *index, int i)
{
	if (i > 0)
		*index += ft_sprintf(line->str + *index, ", ");
	if (line->arg[i].type == T_REG)
		*index += ft_sprintf(line->str + *index, "r");
	else if (line->arg[i].type == T_DIR)
		*index += ft_sprintf(line->str + *index, "%%");
	if (line->arg[i].label == true)
		*index += ft_sprintf(line->str + *index, ":label_%i",
				line->arg[i].id_label);
	else
		*index += ft_sprintf(line->str + *index, "%i",
				line->arg[i].value);
}

static void		s_print(t_line *line)
{
	int		i;
	int		index;

	index = 0;
	if (line->has_label == true || line->index_cor == 0)
		index += ft_sprintf(line->str + index,
				"\nlabel_%i:\n", line->index_cor);
	index += ft_sprintf(line->str + index,
			"    %-8s", line->op.name);
	i = 0;
	while (i < line->op.nb_args)
	{
		s_arg(line, &index, i);
		++i;
	}
	index += ft_sprintf(line->str + index, "\n");
	line->length_str = index;
}

void			line_print(void)
{
	ft_lstd_map(&sgt_dasm()->lines, &s_print);
}
