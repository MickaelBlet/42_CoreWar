/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/29 02:56:32 by mblet             #+#    #+#             */
/*   Updated: 2016/05/29 03:13:58 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdlib.h>

t_hashtable		*ft_hashtable_new(size_t size)
{
	t_hashtable		*ht;

	if ((ht = ft_memalloc(sizeof(t_hashtable))) == NULL)
		return (NULL);
	ht->size = size;
	if ((ht->table = ft_memalloc(sizeof(t_listd *) * size)) == NULL)
	{
		free(ht);
		return (NULL);
	}
	return (ht);
}
