# include "../push_swap.h"

int		ft_loop_list(pst_list *list, pst_list *start1, int set)
{
	pst_list	*loop;
	int			max_tag;
	int 		count;

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

int		ft_find_biggest_loop(pst_list *start, int set)
{
	pst_list	*l;
	int 		max;
	int 		count;
	pst_list	*max_keep;

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

int 	ft_list_size(pst_list *l)
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

	distance = cur_group;
}
