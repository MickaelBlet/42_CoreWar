/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/29 03:01:16 by mblet             #+#    #+#             */
/*   Updated: 2016/05/29 03:09:24 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_hashtable_get(t_hashtable *ht, char *key)
{
	unsigned long int	transform;
	t_listd				*lst;
	t_hashtable_data	*data;

	if (ht == NULL)
		return (NULL);
	transform = ft_hashtable_transform(ht, key);
	lst = ht->table[transform];
	while (lst)
	{
		data = lst->data;
		if (data && ft_strequ(data->key, key))
			return (data->data);
		lst = lst->next;
	}
	return (NULL);
}
