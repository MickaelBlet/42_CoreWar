/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strerror.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/05 16:41:31 by mblet             #+#    #+#             */
/*   Updated: 2016/05/22 21:36:47 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errno/strerror.h"
#include "libft.h"

#include <errno.h>

char	*ft_strerror(void)
{
	static char		**t = NULL;

	if (t == NULL)
		ini_strerror(&t);
	if (t && errno > 0 && errno <= 106)
		return (t[errno]);
	return (NULL);
}

char	*ft_strerr(int err)
{
	static char		**t = NULL;

	if (t == NULL)
		ini_strerror(&t);
	if (t && err > 0 && err <= 106)
		return (t[err]);
	return (NULL);
}
