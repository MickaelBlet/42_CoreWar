/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/29 03:09:28 by mblet             #+#    #+#             */
/*   Updated: 2016/05/29 03:14:55 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <limits.h>

unsigned long int	ft_hashtable_transform(t_hashtable *ht, char *key)
{
	unsigned long int	hashval;
	unsigned int		i;

	hashval = 0;
	i = 0;
	while (hashval < ULONG_MAX && i < ft_strlen(key))
	{
		hashval = hashval << 8;
		hashval += key[i];
		i++;
	}
	return (hashval % ht->size);
}
