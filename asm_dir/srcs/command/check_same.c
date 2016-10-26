/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_same.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/25 20:58:15 by mblet             #+#    #+#             */
/*   Updated: 2016/10/25 21:33:00 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_bool	command_check_same(char *name)
{
	t_listd		*list;
	char		*command;

	list = sgt_asm()->commands;
	while (list != NULL)
	{
		command = list->data;
		if (ft_strequ(command, name))
			return (false);
		list = list->next;
	}
	return (true);
}
