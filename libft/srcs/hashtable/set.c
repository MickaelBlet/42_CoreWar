/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/29 02:36:58 by mblet             #+#    #+#             */
/*   Updated: 2016/05/31 15:08:51 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_bool	s_if_key_exist(t_listd *l, char *key)
{
	t_hashtable_data	*d;

	while (l)
	{
		d = l->data;
		if (d && ft_strequ(d->key, key))
			return (true);
		l = l->next;
	}
	return (false);
}

t_bool			ft_hashtable_set(t_hashtable **ht, char *key, void *data)
{
	t_hashtable_data	*hash;
	unsigned long int	transform;

	if (*ht == NULL)
	{
		if ((*ht = ft_hashtable_new(65536)) == NULL)
			return (false);
	}
	transform = ft_hashtable_transform(*ht, key);
	if (s_if_key_exist((*ht)->table[transform], key) == true)
		return (false);
	if ((hash = ft_memalloc(sizeof(t_hashtable_data))) == NULL)
		return (false);
	hash->key = key;
	hash->data = data;
	ft_lstd_push_front(&(*ht)->table[transform], hash);
	return (true);
}
