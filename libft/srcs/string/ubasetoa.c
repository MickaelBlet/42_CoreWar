/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ubasetoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 18:56:27 by mblet             #+#    #+#             */
/*   Updated: 2016/10/29 11:02:58 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

#include "libft.h"

static void		s_strcal(char **s, unsigned long int n, char *base, size_t len)
{
	if (n < len)
	{
		(**s) = base[n];
		++(*s);
		(**s) = '\0';
	}
	else
	{
		s_strcal(s, n / len, base, len);
		(**s) = base[n % len];
		++(*s);
		(**s) = '\0';
	}
}

char			*ft_ubasetoa(unsigned long int n, char *base)
{
	char	tmp[128];
	char	*str;
	size_t	len_base;
	size_t	len;

	len_base = ft_strlen(base);
	if (len_base < 2)
		return (NULL);
	str = tmp;
	s_strcal(&str, n, base, len_base);
	len = str - tmp + 1;
	if ((str = (char *)malloc((len) * sizeof(char))) == NULL)
		return (NULL);
	ft_memcpy(str, tmp, len);
	return (str);
}
