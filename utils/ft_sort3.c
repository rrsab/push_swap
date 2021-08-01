/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salyce <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 21:09:37 by salyce            #+#    #+#             */
/*   Updated: 2021/08/01 21:09:39 by salyce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_distance_to_tag(int tag, int size)
{
	if (tag >= size / 2)
		tag -= size;
	return (tag);
}

int	ft_insert_distance(pst_list *list, int t, int size)
{
	pst_list	*p;
	pst_list	*c;
	int			c_max[2];
	int			i;

	i = 0;
	p = ft_get_last(list);
	c = list;
	c_max[1] = 0xFFFFFFF;
	while (c)
	{
		if ((p->ind > c->ind && (t < c->ind || t > p->ind))
			|| (t > p->ind && t < c->ind))
		{
			c_max[0] = i;
			if (c_max[0] > size / 2)
				c_max[0] -= size;
			if (ft_abs(c_max[0]) < c_max[1])
				c_max[1] = c_max[0];
		}
		p = c;
		c = c->next;
		i++;
	}
	return (c_max[1]);
}

void	ft_calc_b_rotation(t_heap *heap, int max_dist, int *rot_a, int *rot_b)
{
	int	dist_total;
	int	insert;
	int	distance_b;
	int	i;

	i = 0;
	heap->temp = heap->b;
	while (heap->temp)
	{
		distance_b = ft_distance_to_tag(i++, heap->max - heap->size);
		insert = ft_insert_distance(heap->a, heap->temp->ind, heap->size);
		dist_total = ft_abs(insert) + ft_abs(distance_b);
		if (insert > 0 && distance_b > 0)
			dist_total -= ft_min(distance_b, insert);
		if (insert < 0 && distance_b < 0)
			dist_total += ft_max(distance_b, insert);
		if (dist_total < max_dist)
		{
			max_dist = dist_total;
			*rot_a = insert;
			*rot_b = distance_b;
		}
		heap->temp = heap->temp->next;
	}
}

void	ft_return_a(t_heap *heap)
{
	int	rot_a;
	int	rot_b;

	while (heap->b)
	{
		ft_calc_b_rotation(heap, 0xFFFFFFF, &rot_a, &rot_b);
		ft_rotate(heap, rot_a, rot_b);
		ft_push_a(heap);
		(heap->size)++;
	}
	ft_rotate(heap, ft_distance_to_top(heap->a, 0), 0);
}
