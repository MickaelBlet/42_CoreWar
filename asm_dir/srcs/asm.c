/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/24 21:25:53 by mblet             #+#    #+#             */
/*   Updated: 2016/10/26 03:12:15 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	cor_asm(int argc, char **argv)
{
	int		i;

	i = 0;
	while (++i < argc)
	{
		if (argc > 2)
			ft_printf("%s:\n", argv[i]);
		file_read(argv[i]);
		file_clean();
		if (argc > 2 && i + 1 < argc)
			ft_putchar('\n');
	}
	//while (1);
}
