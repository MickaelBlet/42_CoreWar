/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aish.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/29 13:40:40 by mblet             #+#    #+#             */
/*   Updated: 2016/10/29 13:53:49 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <unistd.h>

t_bool	ft_aish(const char *s)
{
	if (s == NULL || *s == '\0')
		return (false);
	if (*s == '0' && *(s + 1) == 'x')
		s += 2;
	else
		return (false);
	while (*s != '\0' && (
				(*s >= '0' && *s <= '9')
			|| (*s >= 'a' && *s <= 'f')
			|| (*s >= 'A' && *s <= 'F')))
		++s;
	if (*s == '\0')
		return (true);
	return (false);
}
