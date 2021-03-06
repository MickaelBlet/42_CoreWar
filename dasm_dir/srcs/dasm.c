/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dasm.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/28 17:56:34 by mblet             #+#    #+#             */
/*   Updated: 2016/10/29 01:03:07 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dasm.h"

void	dasm(int argc, char **argv)
{
	int		i;

	i = 0;
	while (++i < argc)
	{
		if (argc > 2)
			ft_printf("%s:\n", argv[i]);
		file_read(argv[i]);
		file_clean();
		if (argc > 2)
			ft_putchar('\n');
	}
}
