/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salyce <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 21:11:31 by salyce            #+#    #+#             */
/*   Updated: 2021/08/01 21:12:00 by salyce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_distance_to_top(t_pslist *a, int tag)
{
	int	i;
	int	size;

	i = 0;
	size = ft_list_size(a);
	while (a)
	{
		if (a->ind == tag)
			break ;
		a = a->next;
		i++;
	}
	if (i > size / 2)
		i -= size;
	return (i);
}

t_pslist	*ft_closest_in_group(t_pslist *list, int cur_group, int group_sz)
{
	t_pslist	*closest;
	t_pslist	*cur;
	int			distance;
	int			cur_dist;

	distance = 2147483647;
	closest = NULL;
	cur = list;
	while (cur)
	{
		if (cur->ind <= group_sz * cur_group && !cur->keep)
		{
			cur_dist = ft_distance_to_top(list, cur->ind);
			if (ft_abs(cur_dist) < ft_abs(distance))
			{
				distance = cur_dist;
				closest = cur;
				if (distance == 0)
					break ;
			}
		}
		cur = cur->next;
	}
	return (closest);
}

int	ft_can_swap(t_pslist *list)
{
	t_pslist	l1;
	t_pslist	l2;
	int			count1;
	int			count2;

	l1.next = &l2;
	l1.ind = list->next->ind;
	l2.next = list->next->next;
	l2.ind = list->ind;
	count1 = ft_find_biggest_loop(list, 0);
	count2 = ft_find_biggest_loop(&l1, 0);
	if (count2 > count1)
		return (1);
	return (0);
}

void	ft_double_rotate(t_heap *heap, int *rot_a, int *rot_b)
{
	while (*rot_a > 0 && *rot_b > 0)
	{
		(*rot_a)--;
		(*rot_b)--;
		ft_rotate_a_b(heap);
	}
	while (*rot_a > 0 && *rot_b > 0)
	{
		(*rot_a)++;
		(*rot_b)++;
		ft_rev_rotate_a_b(heap);
	}
}

void	ft_rotate(t_heap *heap, int rot_a, int rot_b)
{
	ft_double_rotate(heap, &rot_a, &rot_b);
	while (rot_a > 0)
	{
		rot_a--;
		ft_rotate_a(heap);
	}
	while (rot_a < 0)
	{
		rot_a++;
		ft_rev_rotate_a(heap);
	}
	while (rot_b > 0)
	{
		rot_b--;
		ft_rotate_b(heap);
	}
	while (rot_b < 0)
	{
		rot_b++;
		ft_rev_rotate_b(heap);
	}
}
