/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ltoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/19 17:56:11 by mblet             #+#    #+#             */
/*   Updated: 2016/10/29 11:17:09 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdlib.h>
#include <unistd.h>

static void		s_strcal(char **s, long long int n, char *base, size_t len)
{
	if (n < 0)
	{
		(**s) = '-';
		++(*s);
		(**s) = '\0';
		n = n * -1;
	}
	if (n < (long long int)len)
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

char			*ft_ltoa(long n)
{
	char	tmp[128];
	char	*str;
	size_t	len;

	if (n == LONG_MIN)
		return (ft_strdup("-9223372036854775808"));
	str = tmp;
	s_strcal(&str, n, "0123456789", 10);
	len = str - tmp + 1;
	if ((str = (char *)malloc((len) * sizeof(char))) == NULL)
		return (NULL);
	ft_memcpy(str, tmp, len);
	return (str);
}
