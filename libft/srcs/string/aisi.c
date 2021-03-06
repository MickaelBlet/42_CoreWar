/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aisi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 20:46:43 by mblet             #+#    #+#             */
/*   Updated: 2016/10/29 13:41:19 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <unistd.h>

t_bool	ft_aisi(const char *s)
{
	if (s == NULL || *s == '\0')
		return (false);
	if (*s == '-' && (*s + 1) != '\0')
		++s;
	while (*s != '\0' && *s >= '0' && *s <= '9')
		++s;
	if (*s == '\0')
		return (true);
	return (false);
}
