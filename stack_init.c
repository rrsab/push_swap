/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salyce <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 21:35:48 by salyce            #+#    #+#             */
/*   Updated: 2021/08/01 21:35:50 by salyce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stack_init(t_pslist **stack, int value, int tag, t_heap *heap)
{
	t_pslist	*elem;
	t_pslist	*last;

	last = *stack;
	if (ft_list_dubl_value(*stack, value))
		ft_exit_error(heap);
	elem = (t_pslist *)malloc(sizeof(t_pslist));
	if (!elem)
		ft_exit_error(heap);
	elem->next = NULL;
	elem->next_sort = NULL;
	elem->value = value;
	elem->ind = tag;
	if (last == NULL)
	{
		*stack = elem;
		return ;
	}
	while (last->next)
		last = last->next;
	last->next = elem;
	last->next_sort = elem;
}
