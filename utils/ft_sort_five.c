# include "../push_swap.h"

int		ft_find_tag(pst_list *list, int tag)
{
	while (list)
	{
		if (list->ind == tag)
			return (1);
		list = list ->next;
	}
	return (0);
}

void	ft_sort_three_list(int m, t_heap *heap)
{
	pst_list	*a;

	a = heap->a;
	if (a->ind == 0 + m && a->next->ind == 2 + m && a->next->next->ind == 1 + m)
	{
		ft_swap_a(heap);
		ft_rotate_a(heap);
	}
	else if (a->ind == 1 + m && a->next->ind == 0 + m && a->next->next->ind
	== 2 + m)
		ft_swap_a(heap);
	else if (a->ind == 1 + m && a->next->ind == 2 + m && a->next->next->ind ==
		0 + m)
		ft_rev_rotate_a(heap);
	else if (a->ind == 2 + m && a->next->ind == 0 + m && a->next->next->ind	==
		1 + m)
		ft_rotate_a(heap);
	else if (a->ind == 2 + m && a->next->ind == 1 + m && a->next->next->ind	==
		0 + m)
	{
		ft_swap_a(heap);
		ft_rev_rotate_a(heap);
	}
}
void	ft_sort_four_list(int m, t_heap *heap)
{
	pst_list	*a;

	a = heap->a;
	if (a->next->ind == 0 + m)
		ft_swap_a(heap);
	else if (a->next->next->ind == 0 + m)
	{
		ft_rotate_a(heap);
		ft_rotate_a(heap);
	}
	else if (a->next->next->next->ind == 0 + m)
		ft_rev_rotate_a(heap);
	if (!ft_check_sort(heap))
	{
		ft_push_b(heap);
		ft_sort_three_list(1 + m, heap);
		ft_push_a(heap);
	}
}

static void	ft_sort_tofive_list(t_heap *heap)
{
	pst_list *a;

	a = heap->a;
	if (a->next->ind == 0)
		ft_swap_a(heap);
	else if (a->next->next->ind == 0)
	{
		ft_rotate_a(heap);
		ft_rotate_a(heap);
	}
	else if (a->next->next->next->ind == 0)
	{
		ft_rev_rotate_a(heap);
		ft_rev_rotate_a(heap);
	}
	else if (a->next->next->next->next->ind == 0)
		ft_rev_rotate_a(heap);
	if (!ft_check_sort(heap))
	{
		ft_push_b(heap);
		ft_sort_four_list(1, heap);
		ft_push_a(heap);
	}
}

void	ft_sort_five_list(t_heap *heap)
{
	if (heap->max == 2)
		ft_swap_a(heap);
	if (heap->max <= 3)
		ft_sort_three_list(0, heap);
	if (heap->max == 4)
		ft_sort_four_list(0, heap);
	if (heap->max == 5)
		ft_sort_tofive_list(heap);
}
