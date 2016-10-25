/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_name.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/25 02:36:44 by mblet             #+#    #+#             */
/*   Updated: 2016/10/25 02:54:26 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_bool	label_check_name(char *name)
{
	int		i;

	if (name == NULL)
		return (false);
	i = 0;
	while (name[i] != '\0')
	{
		if (ft_strchr(LABEL_CHARS, name[i]) == NULL)
			return (false);
		++i;
	}
	return (true);
}
