/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_live.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 00:14:23 by mblet             #+#    #+#             */
/*   Updated: 2016/10/22 13:02:03 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*static void		s_print_list(void)
  {
  t_listd		*list;
  t_process	*process;

  list = sgt_corewar()->process;
  while (list)
  {
  process = list->data;
  DG("%p <- %p - > %p", list->prev, list, list->next);
  list = list->next;
  }
  }*/

void	process_check_live(void)
{
	size_t		i;
	t_listd		*list;
	t_process	*process;

	pthread_mutex_lock(&sgt_corewar()->mutex_process);
	list = sgt_corewar()->process;
	i = ft_lstd_size(list);
	while (list)
	{
		process = list->data;
		if (list->prev == NULL && (process->live <= sgt_corewar()->last_cycle_check || sgt_corewar()->cycle_to_die < 0))
		{
			verbose_death(process);
			ft_lstd_pop_front(&sgt_corewar()->process, NULL);
			list = sgt_corewar()->process;
		}
		else if (process->live <= sgt_corewar()->last_cycle_check || sgt_corewar()->cycle_to_die < 0)
		{
			verbose_death(process);
			ft_lstd_del(&list, NULL);
		}
		else
			list = list->next;
	}
	pthread_mutex_unlock(&sgt_corewar()->mutex_process);
}
