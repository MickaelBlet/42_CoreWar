/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 23:45:55 by mblet             #+#    #+#             */
/*   Updated: 2016/10/27 23:46:49 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void		s_print(t_error *error)
{
	ft_dprintf(STDERR_FILENO, "%s", error->str);
}

void			error_list_print(void)
{
	ft_lstd_map(&sgt_asm()->errors, &s_print);
}
