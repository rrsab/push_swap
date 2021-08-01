/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salyce <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 21:02:31 by salyce            #+#    #+#             */
/*   Updated: 2021/08/01 21:02:37 by salyce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_check_sort(t_heap *m)
{
	int			prev;
	t_pslist	*l;

	if (!m->a)
		return (1);
	l = m->a;
	prev = l->value;
	while (l)
	{
		if (prev > l->value)
			return (0);
		prev = l->value;
		l = l->next;
	}
	return (1);
}

void	ft_swap_list(t_pslist **prevnext, t_pslist *last)
{
	t_pslist	*swap;

	swap = *prevnext;
	*prevnext = last->next_sort;
	swap->next_sort = last->next_sort->next_sort;
	(*prevnext)->next_sort = swap;
}

void	ft_sort_list(t_pslist **start_list)
{
	t_pslist	*last;
	t_pslist	*prev;

	prev = NULL;
	last = *start_list;
	while (last && last->next_sort)
	{
		if (last->value - last->next_sort->value > 0)
		{
			if (prev == NULL)
				ft_swap_list(start_list, last);
			else
				ft_swap_list(&(prev->next_sort), last);
			last = *start_list;
			prev = NULL;
		}
		else
		{
			prev = last;
			last = last->next_sort;
		}
	}
}

void	ft_list_sum(t_pslist *start, t_heap *heap)
{
	int	i;

	i = 0;
	while (start)
	{
		start->ind = i++;
		start = start->next_sort;
	}
	heap->max = i;
}
