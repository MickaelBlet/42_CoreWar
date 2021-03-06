/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/28 04:07:44 by mblet             #+#    #+#             */
/*   Updated: 2016/10/28 19:59:33 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dasm.h"

int		main(int argc, char **argv)
{
	if (argc > 1)
		dasm(argc, argv);
	else
		ft_printf("%s\n", USAGE);
	return (0);
}
