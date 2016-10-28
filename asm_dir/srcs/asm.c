/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/24 21:25:53 by mblet             #+#    #+#             */
/*   Updated: 2016/10/28 00:03:52 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void		s_scan_lexical(t_line *line)
{
	line_scan(0, line);
}

static void		s_scan_op(t_line *line)
{
	line_scan_op(line);
}

void			cor_asm(int argc, char **argv)
{
	int		i;

	i = 0;
	while (++i < argc)
	{
		if (argc > 2)
			ft_printf("%s:\n", argv[i]);
		file_read(argv[i]);
		ft_lstd_map(&sgt_asm()->lines, &s_scan_lexical);
		ft_lstd_map(&sgt_asm()->lines, &s_scan_op);
		if (sgt_asm()->error == false)
			file_write();
		else
			error_list_print();
		file_clean();
		if (argc > 2 && i + 1 < argc)
			ft_putchar('\n');
	}
}
