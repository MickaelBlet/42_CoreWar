/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/19 19:42:26 by mblet             #+#    #+#             */
/*   Updated: 2016/08/18 21:11:52 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "mathft.h"

#include <stdlib.h>
#include <unistd.h>

static size_t	*s_add_i(const char *s, size_t *i)
{
	(void)s;
	++(*i);
	return (i);
}

static double	s_calcul(const char *s, size_t *i)
{
	char	sub[256];
	size_t	pos;
	double	ret;

	if (s[*i] == '+')
		return (s_calcul(s, s_add_i(s, i)));
	else if (s[*i] == '-')
		return (-s_calcul(s, s_add_i(s, i)));
	else if (s[*i] == '(')
	{
		ret = sub_add_mod(s, s_add_i(s, i));
		if (s[*i] == ')')
			s_add_i(s, i);
	}
	else
	{
		pos = *i;
		while ((ft_isdigit(s[*i]) || s[*i] == '.') && (sub[*i - pos] = s[*i]))
			s_add_i(s, i);
		sub[*i - pos] = '\0';
		ret = ft_atof(sub);
	}
	return (ret);
}

static double	s_mul_div(const char *s, size_t *i)
{
	double	ret;

	ret = s_calcul(s, i);
	while (s[*i] != '\0')
	{
		if (s[*i] == '*')
			ret *= s_calcul(s, s_add_i(s, i));
		else if (s[*i] == '/')
			ret /= s_calcul(s, s_add_i(s, i));
		else if (s[*i] == '%')
			ret = (long int)ret % (long int)s_calcul(s, s_add_i(s, i));
		else
			return (ret);
	}
	return (ret);
}

double			sub_add_mod(const char *s, size_t *i)
{
	double	ret;

	ret = s_mul_div(s, i);
	while (s[*i] != '\0')
	{
		if (s[*i] == '+')
			ret += s_mul_div(s, s_add_i(s, i));
		else if (s[*i] == '-')
			ret -= s_mul_div(s, s_add_i(s, i));
		else
			return (ret);
	}
	return (ret);
}

double			ft_do_op(const char *s)
{
	size_t	i;
	char	*str;
	double	ret;

	if (s == NULL)
		return (0);
	i = 0;
	str = ft_strdup(s);
	while (*s != '\0')
	{
		if (ft_strstr("0123456789.+-%/*()", (char[2]){*s, '\0'}) != NULL)
			str[i++] = *s;
		++s;
	}
	str[i] = '\0';
	i = 0;
	ret = sub_add_mod(str, &i);
	ft_strdel(&str);
	return (ret);
}
