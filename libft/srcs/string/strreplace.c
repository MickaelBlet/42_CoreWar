/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strreplace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/23 14:34:18 by mblet             #+#    #+#             */
/*   Updated: 2016/05/24 20:48:11 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strreplace(char *src, char *key, char *rep, size_t start)
{
	char	*ret;
	size_t	len_key;
	size_t	len_rep;

	len_key = ft_strlen(key);
	len_rep = ft_strlen(rep);
	if ((ret = ft_strnew(ft_strlen(src) + len_rep - len_key)) == NULL)
		return (NULL);
	ft_strncpy(ret, src, start);
	ft_strncpy(ret + start, rep, len_rep);
	ft_strcpy(ret + start + len_rep, src + start + len_key);
	return (ret);
}
