/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salyce <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 21:14:55 by salyce            #+#    #+#             */
/*   Updated: 2021/08/01 21:14:58 by salyce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_loop_list(t_pslist *list, t_pslist *start1, int set)
{
	t_pslist	*loop;
	int			max_tag;
	int			count;

	max_tag = -1;
	count = 0;
	loop = start1;
	while (loop)
	{
		if (set)
			loop->keep = 0;
		if (loop->ind > max_tag)
		{
			max_tag = loop->ind;
			count++;
			if (set)
				loop->keep = 1;
		}
		loop = loop->next;
		if (loop == NULL)
			loop = list;
		if (loop == start1)
			break ;
	}
	return (count);
}

int	ft_find_biggest_loop(t_pslist *start, int set)
{
	t_pslist	*l;
	int			max;
	int			count;
	t_pslist	*max_keep;

	max = 0;
	l = start;
	while (l)
	{
		count = ft_loop_list(start, l, 0);
		if (count > max)
		{
			max = count;
			max_keep = l;
		}
		l = l->next;
	}
	if (set)
		ft_loop_list(start, max_keep, 1);
	return (max);
}

int	ft_list_size(t_pslist *l)
{
	int	i;

	i = 0;
	while (l)
	{
		i++;
		l = l->next;
	}
	return (i);
}

void	ft_init_sort(t_heap *heap)
{
	heap->big = ft_find_biggest_loop(heap->a, 1);
	heap->size = ft_list_size(heap->a);
	heap->group_cnt = ft_max(1, (int)(heap->max / 150.0));
	heap->group_sz = heap->max / heap->group_cnt;
}

void	ft_main_sort(t_heap *heap, int cur_group)
{
	int	distance;

	ft_init_sort(heap);
	while (heap->size >= heap->big && cur_group <= (heap->group_cnt + 1))
	{
		heap->temp = ft_closest_in_group(heap->a, cur_group, heap->group_sz);
		if (heap->temp == NULL && ++cur_group)
			continue ;
		distance = ft_distance_to_top(heap->a, heap->temp->ind);
		if (heap->a && ft_can_swap(heap->a))
		{
			ft_swap_a(heap);
			heap->big = ft_find_biggest_loop(heap->a, 1);
		}
		else if (heap->a && !heap->a->keep && distance == 0)
		{
			ft_push_b(heap);
			(heap->size)--;
		}
		else if (heap->group_cnt == 1)
			ft_rotate_a_b(heap);
		else
			ft_rotate(heap, ft_min(1, ft_max(-1, distance)), 0);
	}
	ft_return_a(heap);
}
